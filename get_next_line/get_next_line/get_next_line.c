/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:06:12 by ad-angel          #+#    #+#             */
/*   Updated: 2024/03/22 16:37:32 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	get_next_line1(int fd, t_buffer **buffers)
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
	char_read = 0;
	while (buffer->data[char_read] != '\0')
		char_read++;
	if (char_read == 0)
		char_read = buffer_filling(fd, buffer);
	return (char_read);
}

ssize_t	get_next_line2(int fd, t_buffer *buffer, char **line,
						ssize_t *line_len)
{
	ssize_t		cur;
	ssize_t		char_read;

	cur = 0;
	while (buffer->data[cur] != '\n')
	{
		if (buffer->data[cur] == '\0')
		{
			*line = line_construction(*line, line_len, buffer, cur);
			if (*line == NULL)
				return (-1);
			char_read = buffer_filling(fd, buffer);
			if (char_read == -1)
			{
				free(*line);
				return (-1);
			}
			cur = 0;
			if (char_read == 0)
				break ;
		}
		if (buffer->data[cur] != '\n')
			cur++;
	}
	return (cur);
}

char	*get_next_line3(int fd, t_buffer **buffers)
{
	ssize_t		char_read;
	ssize_t		line_len;
	char		*line;
	t_buffer	*buffer;
	ssize_t		cur;

	char_read = get_next_line1(fd, buffers);
	if (char_read < 1)
		return (NULL);
	line_len = 0;
	line = (char *)malloc(1);
	if (line == NULL)
		return (NULL);
	buffer = buffer_search(fd, *buffers, NULL);
	cur = get_next_line2(fd, buffer, &line, &line_len);
	if (cur == -1)
		return (NULL);
	if (buffer->data[cur] == '\n')
		cur++;
	line = line_construction(line, &line_len, buffer, cur);
	if (line == NULL)
		return (NULL);
	line[line_len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	*buffers = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_next_line3(fd, &buffers);
	if (line == NULL)
	{
		buffer_destroy(fd, &buffers);
		return (NULL);
	}
	return (line);
}
