/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:01:37 by spalta            #+#    #+#             */
/*   Updated: 2023/03/07 14:25:51 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	cpy_stack_a(t_stack *stack)
{
	t_data	*cpy_a = NULL;
	t_data	*n_lst;
	t_data	*tmp;

	tmp = stack->a;
	while (tmp)
	{
		n_lst = p_lstnew(tmp->nbr);
		p_lstadd_back(&cpy_a, n_lst);
		tmp = tmp->next;
	}
	stack->a_cpy = cpy_a;
}

void	sort_stacka(t_stack	*stack)
{
	t_data	*tmp;
	t_data	*tmp1;
	int 	swap;
	
	cpy_stack_a(stack);
	tmp = stack->a_cpy;
	tmp1 = stack->a_cpy;
	while (stack->a_cpy->next)
	{
		if (stack->a_cpy->nbr > stack->a_cpy->next->nbr)
		{
			swap = stack->a_cpy->nbr;
			stack->a_cpy->nbr = stack->a_cpy->next->nbr;
			stack->a_cpy->next->nbr = swap;
			stack->a_cpy = tmp;
		}
		else
			stack->a_cpy = stack->a_cpy->next;
	}
	stack->a_cpy = tmp;
	print_list(stack->a_cpy);
	print_list(stack->a);
}