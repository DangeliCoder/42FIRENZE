/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:12:46 by ad-angel          #+#    #+#             */
/*   Updated: 2024/06/29 13:07:48 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	length(char *str, char delimiter)
{
	int		i;

	i = 0;
	while (str[i] != delimiter && str[i] != '\0')
		i++;
	if (str[i] == '\0' && delimiter != '\0')
		return (-1);
	return (i);
}

void	copy(char *dest, char *sour, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = sour[i];
		i++;
	}
}

int	equal_str(char *str1, char *str2, int com)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (str2[i2] != '\0')
	{
		if (str1[i1] != str2[i2])
			return (0);
		i1++;
		i2++;
	}
	if (str1[i1] != '\0' && !com)
		return (0);
	if (str1[i1] != '\0' && str2[i2 - 1] != ' ')
		return (0);
	return (1);
}

int	prepare_commands(int num_c, char ****argv_c, char **argv, char **env)
{
	int		i;
	char	***argv_c2;
	int		status;

	argv_c2 = new_malloc3((num_c + 1) * sizeof(char **));
	argv_c2[0] = new_malloc2(sizeof(char *));
	argv_c2[0][0] = new_malloc1(sizeof(char));
	argv_c2[0][0][0] = num_c;
	i = 1;
	while (i <= num_c)
	{
		argv_c2[i] = new_malloc2(3 * sizeof(char *));
		status = prepare_command(&argv_c2[i][0], &argv_c2[i][1],
				argv[i + 1], env);
		if (status == 127)
		{
			argv_c2[i][0] = NULL;
			argv_c2[i][1] = NULL;
		}
		argv_c2[i][2] = NULL;
		i++;
	}
	i = 1;
	*argv_c = argv_c2;
	return (status);
}

int	prepare_commands2(int num_c, char ****argv_c, char **argv, char **env)
{
	int		i;
	char	***argv_c2;
	int		status;

	argv_c2 = new_malloc3((num_c + 1) * sizeof(char **));
	argv_c2[0] = new_malloc2(sizeof(char *));
	argv_c2[0][0] = new_malloc1(sizeof(char));
	argv_c2[0][0][0] = num_c;
	i = 1;
	while (i <= num_c)
	{
		argv_c2[i] = new_malloc2(3 * sizeof(char *));
		status = prepare_command(&argv_c2[i][0], &argv_c2[i][1],
				argv[i + 2], env);
		if (status == 127)
		{
			argv_c2[i][0] = NULL;
			argv_c2[i][1] = NULL;
		}
		argv_c2[i][2] = NULL;
		i++;
	}
	*argv_c = argv_c2;
	return (status);
}
