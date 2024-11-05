/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 04:16:05 by ad-angel          #+#    #+#             */
/*   Updated: 2024/07/03 04:16:08 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dealloc_commands(int num_c, char ***argv_c)
{
	int	i;

	free(argv_c[0][0]);
	free(argv_c[0]);
	i = 1;
	while (i <= num_c)
	{
		if (argv_c[i][0] != NULL)
			free(argv_c[i][0]);
		if (argv_c[i][1] != NULL)
			free(argv_c[i][1]);
		free(argv_c[i]);
		i++;
	}
	free(argv_c);
}

void	close_files(int *fd_io, char *file_input)
{
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	if (equal_str(file_input, "here_doc", 0))
		unlink("here_doc");
}

int	search_delim(char *var_path, char delimiter)
{
	int		delim;

	delim = length(var_path, delimiter);
	if (delim == -1)
		delim = length(var_path, '\0');
	return (delim);
}

int	search_var(char **env)
{
	char	*header_var;
	int		i;
	int		j;

	header_var = "PATH=";
	i = 0;
	while (env[i][0] != '\0')
	{
		j = 0;
		while (header_var[j] != '\0')
		{
			if (env[i][j] != header_var[j])
				break ;
			j++;
		}
		if (header_var[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*set_string(char *sour, char delimiter)
{
	int		len;
	char	*dest;
	int		i;

	len = length(sour, delimiter);
	if (len == -1)
		len = length(sour, '\0');
	dest = new_malloc1((len + 1) * sizeof(char));
	i = 0;
	while (i < len)
	{
		dest[i] = sour[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
