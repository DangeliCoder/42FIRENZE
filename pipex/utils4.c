/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 02:46:22 by ad-angel          #+#    #+#             */
/*   Updated: 2024/07/23 02:46:28 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*new_malloc1(int dim)
{
	char	*res;

	res = malloc(dim);
	if (res == NULL)
	{
		error_message("Errore nella allocazione della memoria.", -2);
		exit(1);
	}
	return (res);
}

char	**new_malloc2(int dim)
{
	char	**res;

	res = malloc(dim);
	if (res == NULL)
	{
		error_message("Errore nella allocazione della memoria.", -2);
		exit(1);
	}
	return (res);
}

char	***new_malloc3(int dim)
{
	char	***res;

	res = malloc(dim);
	if (res == NULL)
	{
		error_message("Errore nella allocazione della memoria.", -2);
		exit(1);
	}
	return (res);
}

void	add_null(char *str)
{
	int	buf_len;

	buf_len = length(str, '\n');
	str[buf_len] = '\0';
}

void	create_here_doc(char *limiter)
{
	int		fd;
	char	*prompt;
	char	buffer[128];

	fd = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0xFFF);
	if (fd == -1)
		return ;
	prompt = "heredoc> ";
	write(1, prompt, length(prompt, '\0'));
	read(0, buffer, 128);
	add_null(buffer);
	while (!equal_str(buffer, limiter, 0))
	{
		write(fd, buffer, length(buffer, '\0'));
		write(fd, "\n", 1);
		write(1, prompt, length(prompt, '\0'));
		read(0, buffer, 128);
		add_null(buffer);
	}
	close(fd);
}
