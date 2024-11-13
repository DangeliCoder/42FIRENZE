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

int	final_process(int *fd_io, int ind_c, char ***argv_c, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		dup2(fd_io[1], 1);
		command_exec(ind_c, argv_c, env, fd_io);
		return (0);
	}
	if (argv_c[ind_c][0] == NULL)
		return (0);
	if (!equal_str(argv_c[ind_c][0], "sleep", 0))
		waitpid(pid, NULL, 0);
	return (0);
}

int	pipe_management(pid_t pid, int *p, int ind_c, char ***argv_c)
{
	if (pid == 0)
	{
		close(p[0]);
		dup2(p[1], 1);
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		if (argv_c[ind_c][0] == NULL)
			return (0);
		if (!equal_str(argv_c[ind_c][0], "sleep", 0))
			waitpid(pid, NULL, 0);
	}
	return (0);
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
		pipe_management(pid, p, ind_c, argv_c);
		command_exec(ind_c, argv_c, env, fd_io);
		return (0);
	}
	pipe_management(pid, p, ind_c, argv_c);
	processes(fd_io, ind_c + 1, argv_c, env);
	return (0);
}

int	start_processes(int *fd_io, char ***argv_c, char **env)
{
	int		i;
	int		sleep_time;
	pid_t	pid;

	sleep_time = 0;
	i = 1;
	while (i <= argv_c[0][0][0])
	{
		if (argv_c[i][0] != NULL)
			if (equal_str(argv_c[i][0], "sleep", 0) && argv_c[i][1] != NULL)
				if (string_to_num(argv_c[i][1]) > sleep_time)
					sleep_time = string_to_num(argv_c[i][1]);
		i++;
	}
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
		return (processes(fd_io, 1, argv_c, env));
	sleep(sleep_time);
	if (!equal_str(argv_c[1][0], "sleep", 0))
		waitpid(pid, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_io[2];
	char	***argv_c;
	int		files_status;
	int		commands_status;

	if (argc != 5)
		return (error_message("ERROR: wrong number of parameters.", -2));
	files_status = open_files(argc, argv, fd_io);
	if (files_status > 0)
		argc--;
	if (files_status == 3)
		argc--;
	if (files_status == 1 || files_status == 3)
		commands_status = prepare_commands2(argc - 3, &argv_c, argv, env);
	else
		commands_status = prepare_commands(argc - 3, &argv_c, argv, env);
	if (argc == 5)
		start_processes(fd_io, argv_c, env);
	dealloc_commands(argc - 3, argv_c);
	close_files(fd_io, "");
	if (files_status > 0 && files_status != 4)
		return (1);
	return (commands_status);
}
