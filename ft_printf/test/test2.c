/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:08:00 by ad-angel          #+#    #+#             */
/*   Updated: 2023/12/28 22:10:27 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "libftprintf.h"

int	main(void)
{
	const char	*format;

	format = "%#30i\n";
	printf("\nft_printf :\n");
	printf("\n%i\n", ft_printf(format, INT_MIN));
	printf("\nprintf :\n");
	printf("\n%i\n", printf(format, INT_MIN));
	return (0);
}
