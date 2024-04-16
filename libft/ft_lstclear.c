/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:36:25 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/20 16:36:28 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux2;

	if (lst == NULL || del == NULL)
		return ;
	aux = *lst;
	while (aux != NULL)
	{
		del(aux->content);
		aux2 = aux;
		aux = aux->next;
		free(aux2);
	}
	*lst = NULL;
}
