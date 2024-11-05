/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:46:53 by ad-angel          #+#    #+#             */
/*   Updated: 2024/05/27 11:47:05 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int		length(char *str, char c);
void	copy(char *dest, char *sour, int len);
int		equal_str(char *str1, char *str2, int com);
int		prepare_commands(int num_c, char ****argv_c, char **argv, char **env);
int		prepare_commands2(int num_c, char ****argv_c, char **argv, char **env);
void	dealloc_commands(int num_c, char ***argv_c);
void	close_files(int *fd_io, char *file_input);
int		search_delim(char *var_path, char delimiter);
int		search_var(char **env);
char	*set_string(char *sour, char delimiter);
int		prepare_command(char **cmd, char **arg2, char *arg1, char **env);
int		prepare_command2(char **cmd, char **arg2, char *arg1, char **env);
char	*new_malloc1(int dim);
char	**new_malloc2(int dim);
char	***new_malloc3(int dim);
void	create_here_doc(char *limiter);
int		open_outfile(char *outfile, int status);
int		error_message(char *object, int error_number);
int		string_to_num(char *str);
void	command_exec(int ind_c, char ***argv_c, char **env, int *fd_io);
