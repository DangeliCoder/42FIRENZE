/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:59:18 by ad-angel          #+#    #+#             */
/*   Updated: 2024/04/11 13:31:56 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	buffer_search(int fd, t_buffer *buffers, ssize_t *prec_buffer)
{
	ssize_t	start;
	ssize_t	mid;
	ssize_t	end;

	start = 1;
	end = buffers[0].buffers_size - 1;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (buffers[mid].fd == fd)
			return (mid);
		if (buffers[mid].fd > fd)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (buffers[start].fd == fd)
		return (start);
	if (buffers[end].fd == fd)
		return (end);
	if (buffers[start].fd > fd)
		*prec_buffer = start - 1;
	if (buffers[end].fd < fd)
		*prec_buffer = end;
	return (-1);
}

t_buffer	*buffers_initialization(t_buffer *buffers, ssize_t prec_buffer)
{
	ssize_t		buffers_size;
	t_buffer	*buffers_aux;
	ssize_t		index;

	if (buffers != NULL)
		buffers_size = buffers[0].buffers_size;
	else
		buffers_size = 1;
	buffers_aux = (t_buffer *)malloc(sizeof(t_buffer) * (buffers_size + 1));
	if (buffers_aux == NULL)
		return (NULL);
	index = 1;
	while (index < buffers_size)
	{
		if (index <= prec_buffer)
			buffers_aux[index] = buffers[index];
		else
			buffers_aux[index + 1] = buffers[index];
		index++;
	}
	if (buffers != NULL)
		free(buffers);
	buffers_size++;
	buffers_aux[0].buffers_size = buffers_size;
	return (buffers_aux);
}

ssize_t	buffer_filling(int fd, t_buffer buffer)
{
	ssize_t	char_read;

	char_read = 0;
	while (buffer.data[char_read] != '\0')
		char_read++;
	if (char_read == 0)
	{
		char_read = read(fd, buffer.data, BUFFER_SIZE);
		if (char_read == -1)
			return (-1);
		buffer.data[char_read] = '\0';
	}
	return (char_read);
}

void	buffer_destroy(t_buffer **buffers, ssize_t index)
{
	t_buffer	*buffers_aux;
	ssize_t		index2;

	buffers[0]->buffers_size--;
	if (buffers[0]->buffers_size == 1)
	{
		free((*buffers)[index].data);
		free(*buffers);
		*buffers = NULL;
		return ;
	}
	buffers_aux = (t_buffer *)malloc(sizeof(t_buffer)
			* buffers[0]->buffers_size);
	index2 = 0;
	while (index2 < buffers[0]->buffers_size)
	{
		if (index2 < index)
			buffers_aux[index2] = (*buffers)[index2];
		else
			buffers_aux[index2] = (*buffers)[index2 + 1];
		index2++;
	}
	free((*buffers)[index].data);
	free(*buffers);
	*buffers = buffers_aux;
}

char	*line_construction(char *line, ssize_t *line_len, t_buffer buffer,
						ssize_t add_len)
{
	char	*line2;
	int		i;

	line2 = (char *)malloc(*line_len + add_len + 1);
	if (line2 != NULL)
	{
		i = 0;
		while (i < (*line_len + add_len))
		{
			if (i < *line_len)
				line2[i] = line[i];
			else
				line2[i] = buffer.data[i - *line_len];
			i++;
		}
		(*line_len) += add_len;
		i = 0;
		while (i < (BUFFER_SIZE + 1 - add_len))
		{
			buffer.data[i] = buffer.data[i + add_len];
			i++;
		}
	}
	free(line);
	return (line2);
}
