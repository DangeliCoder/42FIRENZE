/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:11:31 by ad-angel          #+#    #+#             */
/*   Updated: 2024/10/16 19:11:37 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_outfile(char *outfile, int status)
{
	if (status == 4)
		return (open(outfile, O_RDWR | O_CREAT | O_APPEND, 0xFFF));
	return (open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0xFFF));
}

int	error_message(char *object, int error_number)
{
	write(2, object, length(object, '\0'));
	if (error_number > -2)
		write(2, ": ", 2);
	if (error_number > -1)
		write(2, strerror(error_number), length(strerror(error_number), '\0'));
	else if (error_number == -1)
		write(2, ": command not found", 19);
	write(2, "\n", 1);
	return (1);
}

int	string_to_num(char *str)
{
	int	exp;
	int	power;
	int	number;
	int	i;

	exp = length(str, '\0') - 1;
	power = 1;
	while (exp >= 1)
	{
		power *= 10;
		exp--;
	}
	number = 0;
	i = 0;
	while (power >= 1)
	{
		number += (power * (str[i] - 0x30));
		i++;
		power /= 10;
	}
	return (number);
}

void	command_exec(int ind_c, char ***argv_c, char **env, int *fd_io)
{
	int	status_code;

	if (argv_c[ind_c][0] == NULL)
		return ;
	if (equal_str(argv_c[ind_c][0], "sleep", 0))
		return ;
	if (!equal_str(argv_c[ind_c][0], "exit", 0))
	{
		execve(argv_c[ind_c][0], argv_c[ind_c], env);
		close_files(fd_io, "");
		dealloc_commands(argv_c[0][0][0], argv_c);
		exit(126);
	}
	close_files(fd_io, "");
	if (argv_c[ind_c][1] == NULL)
	{
		dealloc_commands(argv_c[0][0][0], argv_c);
		exit(0);
	}
	status_code = string_to_num(argv_c[ind_c][1]);
	dealloc_commands(argv_c[0][0][0], argv_c);
	exit(status_code);
}

int	open_files(int argc, char **argv, int *fd_io)
{
	int	status;

	status = 0;
	if (equal_str(argv[1], "here_doc", 0))
	{
		create_here_doc(argv[2]);
		status = 4;
	}
	fd_io[0] = open(argv[1], O_RDONLY);
	if (fd_io[0] == -1)
	{
		error_message(argv[1], errno);
		if (status == 4)
			exit(1);
		fd_io[0] = open("/dev/null", O_RDONLY);
		status = 1;
	}
	fd_io[1] = open_outfile(argv[argc - 1], status);
	if (fd_io[1] == -1)
	{
		error_message(argv[argc - 1], errno);
		status += 2;
	}
	return (status);
}
