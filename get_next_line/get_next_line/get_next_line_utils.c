/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:59:18 by ad-angel          #+#    #+#             */
/*   Updated: 2024/03/22 16:38:06 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buffer	*buffer_search(int fd, t_buffer *buffers, t_buffer **prec_buffer)
{
	t_buffer	*buffer;

	if (prec_buffer != NULL)
		*prec_buffer = NULL;
	buffer = buffers;
	while (buffer != NULL)
	{
		if (buffer->fd == fd)
			break ;
		if (prec_buffer != NULL)
			*prec_buffer = buffer;
		buffer = buffer->next;
	}
	return (buffer);
}

t_buffer	*buffer_initialization(int fd, t_buffer **buffers,
				t_buffer *prec_buffer)
{
	t_buffer	*buffer;

	buffer = (t_buffer *)malloc(sizeof(t_buffer));
	if (buffer == NULL)
		return (NULL);
	buffer->data = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer->data == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer->data[0] = '\0';
	buffer->fd = fd;
	buffer->next = NULL;
	if (prec_buffer == NULL)
		*buffers = buffer;
	else
		prec_buffer->next = buffer;
	return (buffer);
}

ssize_t	buffer_filling(int fd, t_buffer *buffer)
{
	ssize_t	char_read;

	char_read = read(fd, buffer->data, BUFFER_SIZE);
	if (char_read == -1)
		return (-1);
	buffer->data[char_read] = '\0';
	return (char_read);
}

void	buffer_destroy(int fd, t_buffer **buffers)
{
	t_buffer	*aux1;
	t_buffer	*aux2;

	aux1 = NULL;
	aux2 = *buffers;
	while (aux2 != NULL)
	{
		if (aux2->fd == fd)
			break ;
		aux1 = aux2;
		aux2 = aux2->next;
	}
	if (aux2 == NULL)
		return ;
	if (aux1 == NULL)
		*buffers = aux2->next;
	else
		aux1->next = aux2->next;
	free(aux2->data);
	aux2->data = NULL;
	free(aux2);
	aux2 = NULL;
}

char	*line_construction(char *line, ssize_t *line_len, t_buffer *buffer,
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
				line2[i] = buffer->data[i - *line_len];
			i++;
		}
		(*line_len) += add_len;
		i = 0;
		while (i < (BUFFER_SIZE + 1 - add_len))
		{
			buffer->data[i] = buffer->data[i + add_len];
			i++;
		}
	}
	free(line);
	return (line2);
}
