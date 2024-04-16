/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:50:18 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/21 10:50:22 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

static void	free_list(t_list **head, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux2;

	if (head == NULL)
		return ;
	aux = *head;
	while (aux != NULL)
	{
		del(aux->content);
		aux->content = NULL;
		aux2 = aux;
		aux = aux->next;
		free(aux2);
		aux2 = NULL;
	}
	*head = NULL;
}

static t_list	*ft_lstmap2(t_list *res, t_list *lst,
		void *(*f)(void *))
{
	while (lst != NULL)
	{
		res->next = (t_list *)malloc(sizeof(t_list));
		if (res->next == NULL)
			return (NULL);
		res = res->next;
		res->content = f(lst->content);
		res->next = NULL;
		lst = lst->next;
	}
	return (res);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res->content = f(lst->content);
	res->next = NULL;
	lst = lst->next;
	if (ft_lstmap2(res, lst, f) == NULL)
		free_list(&res, del);
	return (res);
}
