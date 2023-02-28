/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:28:51 by spalta            #+#    #+#             */
/*   Updated: 2023/02/28 15:44:10 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*p_lstlast(t_data *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	p_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*list;

	list = p_lstlast((*lst));
	if (!list)
		*lst = new;
	else
		list->next = new;
}

void	p_lstadd_front(t_data **lst, t_data *new)
{
	new->next = *lst;
	*lst = new;
}

t_data	*p_lstnew(int nbr)
{
	t_data	*node;

	node = malloc (sizeof(t_data));
	if (!node)
		return (0);
	node->nbr = nbr;
	node->next = 0;
	return (node);
}