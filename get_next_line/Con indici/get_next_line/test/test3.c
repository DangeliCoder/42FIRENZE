/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:59:29 by ad-angel          #+#    #+#             */
/*   Updated: 2024/02/02 16:59:32 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*text;

	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (1);
	text = get_next_line(fd);
	while (text != NULL)
	{
		printf("line = %s", text);
		free(text);
		text = get_next_line(fd);
	}
	close(fd);
	return (0);
}
