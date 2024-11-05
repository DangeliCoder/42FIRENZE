/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:59:11 by ad-angel          #+#    #+#             */
/*   Updated: 2024/05/20 12:59:14 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	final_process(int *fd_io, int ind_c, char ***argv_c, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		dup2(fd_io[1], 1);
		execve(argv_c[ind_c][0], argv_c[ind_c], env);
	}
	else
		wait(NULL);
	return (0);
}

void	pipe_management(int child, int *p)
{
	if (child)
	{
		close(p[0]);
		dup2(p[1], 1);
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
	}
}

int	processes(int *fd_io, int ind_c, char ***argv_c, char **env)
{
	pid_t	pid;
	int		p[2];

	if (ind_c == argv_c[0][0][0])
		return (final_process(fd_io, ind_c, argv_c, env));
	if (ind_c == 1)
		dup2(fd_io[0], 0);
	if (pipe(p) < 0)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		pipe_management(1, p);
		execve(argv_c[ind_c][0], argv_c[ind_c], env);
	}
	else
	{
		pipe_management(0, p);
		wait(NULL);
	}
	return (processes(fd_io, ind_c + 1, argv_c, env));
}

int	main(int argc, char **argv, char **env)
{
	int		fd_io[2];
	char	***argv_c;
	int		files_status;
	int		commands_status;

	if (argc < 5)
		return (error_message("ERROR: wrong number of parameters.", -2));
	files_status = open_files(argc, argv, fd_io);
	if (files_status > 0)
		argc--;
	if (files_status == 3 || files_status == 6)
		argc--;
	if (files_status == 1 || files_status >= 3)
		commands_status = prepare_commands2(argc - 3, &argv_c, argv, env);
	else
		commands_status = prepare_commands(argc - 3, &argv_c, argv, env);
	if (argc >= 5 && (files_status < 2 || files_status == 4))
		processes(fd_io, 1, argv_c, env);
	dealloc_commands(argc - 3, argv_c);
	close_files(fd_io, argv[1]);
	if (files_status > 0 && files_status != 4)
		return (1);
	return (commands_status);
}
