/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:31:39 by ad-angel          #+#    #+#             */
/*   Updated: 2024/07/03 04:16:25 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	compose_commmand(char *dest, char *cmd, char *path, int path_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < path_len)
	{
		dest[i] = path[i];
		i++;
	}
	dest[i] = '/';
	i++;
	j = 0;
	while (cmd[j] != '\0' && cmd[j] != ' ')
	{
		dest[i] = cmd[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*add_path(char *cmd, char **env)
{
	int		i;
	char	*var_path;
	int		delim;
	char	*aux;

	if (length(cmd, '/') == 0)
		return (set_string(cmd, ' '));
	i = search_var(env);
	if (i < 0)
		return (NULL);
	var_path = env[i];
	delim = length(var_path, '=');
	var_path += (delim + 1);
	aux = new_malloc1(length(var_path, '\0') + 1 + length(cmd, '\0'));
	delim = search_delim(var_path, ':');
	while (delim > 0)
	{
		compose_commmand(aux, cmd, var_path, delim);
		if (access(aux, F_OK | X_OK) != -1)
			return (aux);
		var_path += (delim + 1);
		delim = search_delim(var_path, ':');
	}
	free(aux);
	return (NULL);
}

char	*prepare_argument(char *arg1)
{
	int		len;
	char	*aux;

	len = length(arg1, ' ');
	if (len < 0)
		return (NULL);
	len++;
	arg1 += len;
	len = length(arg1, '\0');
	aux = new_malloc1(len + 1);
	copy(aux, arg1, len);
	aux[len] = '\0';
	return (aux);
}

int	prepare_command(char **cmd, char **arg2, char *arg1, char **env)
{
	char	*aux;

	if (!equal_str(arg1, "sleep", 1) && !equal_str(arg1, "sleep ", 1))
		aux = add_path(arg1, env);
	else
		aux = set_string("sleep", '\0');
	if (aux == NULL)
	{
		error_message(arg1, -1);
		return (127);
	}
	*cmd = aux;
	*arg2 = prepare_argument(arg1);
	return (0);
}

int	prepare_command2(char **cmd, char **arg2, char *arg1, char **env)
{
	char	*aux;

	if (!equal_str(arg1, "exit", 1) && !equal_str(arg1, "exit ", 1)
		&& !equal_str(arg1, "sleep", 1) && !equal_str(arg1, "sleep ", 1))
		aux = add_path(arg1, env);
	else
	{
		if (equal_str(arg1, "sleep", 1) || equal_str(arg1, "sleep ", 1))
			aux = set_string("sleep", '\0');
		else
			aux = set_string("exit", '\0');
	}
	if (aux == NULL)
	{
		error_message(arg1, -1);
		return (127);
	}
	*cmd = aux;
	*arg2 = prepare_argument(arg1);
	if (equal_str(*cmd, "exit", 0) && *arg2 != NULL)
		return (string_to_num(*arg2));
	return (0);
}
