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

int	open_files(char *file_input, char *file_output, int *fd_io)
{
	int	status;

	status = 0;
	fd_io[0] = open(file_input, O_RDONLY);
	if (fd_io[0] == -1)
	{
		error_message(file_input, errno);
		status++;
	}
	fd_io[1] = open(file_output, O_RDWR | O_CREAT | O_TRUNC, 0xFFF);
	if (fd_io[1] == -1)
	{
		error_message(file_output, errno);
		status += 2;
	}
	return (status);
}

int	final_process(int *fd_io, int ind_c, char ***argv_c, char **env)
{
	pid_t	pid;
	int		sleep_time;

	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(fd_io[1], 1);
		command_exec(ind_c, argv_c, env, fd_io);
		return (0);
	}
	sleep_time = 0;
	if (argv_c[ind_c][0] == NULL)
		return (0);
	if (!equal_str(argv_c[ind_c][0], "sleep", 0))
		waitpid(pid, NULL, 0);
	else
		sleep_time = string_to_num(argv_c[ind_c][1]);
	return (sleep_time);
}

int	pipe_management(pid_t pid, int *p, int ind_c, char ***argv_c)
{
	int		sleep_time;

	sleep_time = 0;
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
		else
			sleep_time = string_to_num(argv_c[ind_c][1]);
	}
	return (sleep_time);
}

int	processes(int *fd_io, int ind_c, char ***argv_c, char **env)
{
	pid_t	pid;
	int		p[2];
	int		sleep_time1;
	int		sleep_time2;

	if (ind_c == argv_c[0][0][0])
		return (final_process(fd_io, ind_c, argv_c, env));
	if (ind_c == 1)
		dup2(fd_io[0], 0);
	if (pipe(p) < 0)
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		pipe_management(pid, p, ind_c, argv_c);
		command_exec(ind_c, argv_c, env, fd_io);
		return (0);
	}
	sleep_time1 = pipe_management(pid, p, ind_c, argv_c);
	sleep_time2 = processes(fd_io, ind_c + 1, argv_c, env);
	if (sleep_time1 > sleep_time2)
		return (sleep_time1);
	return (sleep_time2);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_io[2];
	char	***argv_c;
	int		files_status;
	int		commands_status;

	if (argc != 5)
		return (error_message("ERROR: wrong number of parameters.", -2));
	files_status = open_files(argv[1], argv[argc - 1], fd_io);
	if (files_status > 0)
		argc--;
	if (files_status == 3)
		argc--;
	if (files_status == 1 || files_status == 3)
		commands_status = prepare_commands2(argc - 3, &argv_c, argv, env);
	else
		commands_status = prepare_commands(argc - 3, &argv_c, argv, env);
	if (argc == 5)
		sleep(processes(fd_io, 1, argv_c, env));
	dealloc_commands(argc - 3, argv_c);
	close_files(fd_io, "");
	if (files_status > 0 && files_status != 4)
		return (1);
	return (commands_status);
}
