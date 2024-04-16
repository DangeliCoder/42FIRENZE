/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:01:55 by ad-angel          #+#    #+#             */
/*   Updated: 2024/04/10 04:25:35 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <malloc.h>

typedef struct s_buffer
{
	ssize_t	buffers_size;
	int		fd;
	char	*data;
}	t_buffer;

ssize_t		buffer_search(int fd, t_buffer *buffers, ssize_t *prec_buffer);
t_buffer	*buffers_initialization(t_buffer *buffers, ssize_t prec_buffer);
ssize_t		buffer_filling(int fd, t_buffer buffer);
void		buffer_destroy(t_buffer **buffers, ssize_t index);
char		*line_construction(char *line, ssize_t *line_len, t_buffer buffer,
				ssize_t add_len);
char		*get_next_line(int fd);

#endif
