/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:19:00 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/07 15:44:49 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	d;

	d = 48;
	while (d < 58)
	{
		write(1, &d, 1);
		d++;
	}
}
/*
int main()
{
	ft_print_numbers();
	return 0;
}*/
