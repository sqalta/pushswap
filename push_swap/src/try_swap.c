/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:34:42 by spalta            #+#    #+#             */
/*   Updated: 2023/03/08 14:51:10 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_min_max(t_data *f_i, int min, int max)
{
	t_data	*l_i;
	l_i = p_lstlast(f_i);
	
	if ((f_i->inx == min) || (f_i->inx == max))
		return (1);
	return (0);
}

int	is_push(t_data *a, t_data *b)
{
	int f_a = a->inx;
	int l_a = p_lstlast(a)->inx;
	int f_b;
	int l_b;
	if (!b->next)
	{
		f_b = b->inx;
		l_b = f_b;
	}
	else
	{
		l_b = p_lstlast(b)->inx;
		f_b = b->inx;
	}
	if (abs(f_a - f_b) == 1)
		return (1);
	else if (abs(l_a - l_b) == 1)
		return (2); // rrr
	else
		return (0);
}

void p_s(t_stack *stack)
{
	int max = p_lstsize(stack->a) - 1;
	int min = 0;
	t_data	*tmp;
	int	flag;

	tmp = stack->a;
	while (p_lstsize(stack->a) != 2)
	{
		flag = is_min_max(stack->a, min, max);
		if (flag == 1)
			rra(stack);
		else
			pb(stack);
	}
	print_list(stack->a);
	p_lstsize(stack->a);
	while (stack->b)
	{
		flag = is_push(stack->a, stack->b);
		if (flag == 1)
		{
			pa(stack);
		}
		if (flag == 2)
		{
			rrr(stack);
			pa(stack);
		}
		else
			rb(stack);
	}
	while (stack->a->inx != 0)
		pb(stack);
	ra(stack);
	while (stack->b)
	{
		rrb(stack);
		pa(stack);
	}
	print_list(stack->a);
}