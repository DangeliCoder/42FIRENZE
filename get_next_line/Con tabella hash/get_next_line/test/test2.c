/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:59:29 by ad-angel          #+#    #+#             */
/*   Updated: 2024/03/30 01:38:50 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

void	main1(int fd1, int fd2)
{
	char	*text1;
	char	*text2;

	text1 = get_next_line(fd1);
	text2 = get_next_line(fd2);
	while (text1 != NULL || text2 != NULL)
	{
		if (text1 != NULL)
		{
			printf("line1 = %s", text1);
			free(text1);
		}
		if (text2 != NULL)
		{
			printf("line2 = %s", text2);
			free(text2);
		}
		text1 = get_next_line(fd1);
		text2 = get_next_line(fd2);
	}
}

int	main(void)
{
	int		fd1;
	int		fd2;

	fd1 = open("prova9.txt", O_RDWR);
	if (fd1 == -1)
		return (1);
	fd2 = open("prova1.txt", O_RDWR);
	if (fd2 == -1)
		return (1);
	main1(fd1, fd2);
	close(fd1);
	close(fd2);
	return (0);
}
