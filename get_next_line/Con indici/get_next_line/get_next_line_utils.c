/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:59:18 by ad-angel          #+#    #+#             */
/*   Updated: 2024/04/12 03:07:37 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (NULL);
	}
	buffer->start = 0;
	buffer->end = 0;
	buffer->fd = fd;
	buffer->next = NULL;
	if (prec_buffer == NULL)
		*buffers = buffer;
	else
		prec_buffer->next = buffer;
	return (buffer);
}

ssize_t	buffer_filling(int fd, t_buffer **buffers)
{
	t_buffer	*prec_buffer;
	t_buffer	*buffer;
	ssize_t		char_read;

	prec_buffer = NULL;
	buffer = buffer_search(fd, *buffers, &prec_buffer);
	if (buffer == NULL)
	{
		buffer = buffer_initialization(fd, buffers, prec_buffer);
		if (buffer == NULL)
			return (-1);
	}
	if (buffer->end > buffer->start)
		return (1);
	buffer->start = 0;
	char_read = read(fd, buffer->data, BUFFER_SIZE);
	if (char_read == -1)
		return (-1);
	buffer->end = char_read;
	return (char_read);
}

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
	free(aux2);
}

char	*line_copy(char *line, ssize_t *line_len, t_buffer *buffer,
						ssize_t add_len)
{
	char	*line2;

	if (add_len >= 0)
		line2 = (char *)malloc(*line_len + add_len + 1);
	else
		line2 = NULL;
	if (line2 == NULL)
	{
		free(line);
		return (NULL);
	}
	memcpy(line2, line, *line_len);
	free(line);
	memcpy(line2 + *line_len, buffer->data + buffer->start, add_len);
	(*line_len) += add_len;
	buffer->start += add_len;
	return (line2);
}
