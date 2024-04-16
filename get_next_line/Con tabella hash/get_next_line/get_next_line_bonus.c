/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:06:12 by ad-angel          #+#    #+#             */
/*   Updated: 2024/04/10 04:25:23 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	get_next_line1(int fd, t_buffer **buffers, ssize_t *index)
{
	ssize_t		prec_buffer;
	t_buffer	*buffers_aux;

	prec_buffer = 0;
	if (*buffers != NULL)
		*index = buffer_search(fd, *buffers, &prec_buffer);
	if (*index == -1)
	{
		buffers_aux = buffers_initialization(*buffers, prec_buffer);
		if (buffers_aux == NULL)
			return (-1);
		*index = prec_buffer + 1;
		buffers_aux[*index].data = (char *)malloc(BUFFER_SIZE + 1);
		if (buffers_aux[*index].data == NULL)
		{
			free(buffers_aux);
			return (-1);
		}
		buffers_aux[*index].data[0] = '\0';
		buffers_aux[*index].fd = fd;
		*buffers = buffers_aux;
	}
	return (buffer_filling(fd, (*buffers)[*index]));
}

ssize_t	get_next_line2(int fd, t_buffer buffer, char **line,
						ssize_t *line_len)
{
	ssize_t		cur;
	ssize_t		char_read;

	cur = 0;
	while (buffer.data[cur] != '\n')
	{
		if (buffer.data[cur] == '\0')
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
		if (buffer.data[cur] != '\n')
			cur++;
	}
	return (cur);
}

char	*get_next_line3(int fd, t_buffer **buffers, ssize_t *index)
{
	ssize_t		char_read;
	ssize_t		line_len;
	char		*line;
	ssize_t		cur;

	char_read = get_next_line1(fd, buffers, index);
	if (char_read < 1)
		return (NULL);
	line_len = 0;
	line = (char *)malloc(1);
	if (line == NULL)
		return (NULL);
	cur = get_next_line2(fd, (*buffers)[*index], &line, &line_len);
	if (cur == -1)
		return (NULL);
	if ((*buffers)[*index].data[cur] == '\n')
		cur++;
	line = line_construction(line, &line_len, (*buffers)[*index], cur);
	if (line == NULL)
		return (NULL);
	line[line_len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	*buffers = NULL;
	ssize_t			index;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = -1;
	line = get_next_line3(fd, &buffers, &index);
	if (line == NULL)
	{
		if (buffers != NULL)
			buffer_destroy(&buffers, index);
		return (NULL);
	}
	return (line);
}
