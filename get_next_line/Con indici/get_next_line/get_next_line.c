/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:06:12 by ad-angel          #+#    #+#             */
/*   Updated: 2024/04/12 03:07:54 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line1(int fd, t_buffer **buffers)
{
	ssize_t	char_read;
	char	*line;

	char_read = buffer_filling(fd, buffers);
	if (char_read < 1)
	{
		buffer_destroy(fd, buffers);
		return (NULL);
	}
	line = (char *)malloc(char_read + 1);
	if (line == NULL)
	{
		buffer_destroy(fd, buffers);
		return (NULL);
	}
	return (line);
}

ssize_t	get_next_line2(int fd, t_buffer **buffers, char **line,
						ssize_t *line_len)
{
	t_buffer	*aux;
	ssize_t		cur;
	ssize_t		char_read;

	aux = buffer_search(fd, *buffers, NULL);
	cur = aux->start;
	while (aux->data[cur] != '\n')
	{
		cur++;
		if (cur == aux->end)
		{
			char_read = -1;
			*line = line_copy(*line, line_len, aux, cur - aux->start);
			if (*line != NULL)
				char_read = buffer_filling(fd, buffers);
			if (char_read == -1)
				return (-1);
			cur = 0;
			if (char_read == 0)
				break ;
		}
	}
	return (cur);
}

ssize_t	get_next_line3(int fd, t_buffer **buffers, char **line,
						ssize_t *line_len)
{
	ssize_t	cur;

	*line = get_next_line1(fd, buffers);
	if (*line == NULL)
		return (-1);
	cur = get_next_line2(fd, buffers, line, line_len);
	return (cur);
}

char	*get_next_line4(t_buffer *buffer, char *line, ssize_t *line_len,
						ssize_t cur)
{
	if (buffer->data[cur] == '\n' && cur < buffer->end)
		cur++;
	line = line_copy(line, line_len, buffer, cur - buffer->start);
	if (line == NULL)
		return (NULL);
	line[*line_len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	*buffers = NULL;
	ssize_t			line_len;
	char			*line;
	ssize_t			cur;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer_destroy(fd, &buffers);
		return (NULL);
	}
	line_len = 0;
	cur = get_next_line3(fd, &buffers, &line, &line_len);
	if (cur == -1)
	{
		buffer_destroy(fd, &buffers);
		return (NULL);
	}
	line = get_next_line4(buffer_search(fd, buffers, NULL), line,
			&line_len, cur);
	if (line == NULL)
	{
		buffer_destroy(fd, &buffers);
		return (NULL);
	}
	return (line);
}
