/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:01:55 by ad-angel          #+#    #+#             */
/*   Updated: 2024/04/12 03:08:07 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <malloc.h>
# include <string.h>

typedef struct s_buffer
{
	int				fd;
	char			*data;
	ssize_t			start;
	ssize_t			end;
	struct s_buffer	*next;
}	t_buffer;

t_buffer	*buffer_initialization(int fd, t_buffer **buffers,
				t_buffer *prec_buffer);
ssize_t		buffer_filling(int fd, t_buffer **buffers);
t_buffer	*buffer_search(int fd, t_buffer *buffers, t_buffer **prec_buffer);
void		buffer_destroy(int fd, t_buffer **buffers);
char		*line_copy(char *line, ssize_t *line_len, t_buffer *buffer,
				ssize_t add_len);
char		*get_next_line(int fd);

#endif
