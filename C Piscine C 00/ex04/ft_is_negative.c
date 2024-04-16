/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:54:12 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/07 16:13:36 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	r;

	if (n >= 0)
		r = 'P';
	else
		r = 'N';
	write(1, &r, 1);
}
/*
int main()
{
	ft_is_negative(-1);
	ft_is_negative(5);
	ft_is_negative(0);
}*/
