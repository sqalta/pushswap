/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:18:06 by spalta            #+#    #+#             */
/*   Updated: 2023/03/11 17:23:55 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_stack *stack, int min, int max)
{
	t_data	*a;
	
	a = stack->a;
	while (a)
	{
		if (a->inx == min)
			a->is_min = 1;
		if (a->inx == max)
			a->is_max = 1;
		a = a->next;
	}
	a = stack->a;
}

void	a_min_max(t_stack *stack) // a stack 1 kalırsa dikkatli ol!;
{
	t_data	*a;
	int		min;
	int		max;

	a = stack->a;
	min = stack->a->inx;
	max = stack->a->inx;
	while (a->next)
	{
		if (a->next->inx < min)
		{
			min = a->next->inx;
		}
		a = a->next;
	}
	a = stack->a;
	while (a->next)
	{
		if (a->next->inx > max)
		{
			max = a->next->inx;
		}
		a = a->next;
	}
	find_min_max(stack, min, max);
}

void	position(t_data *stack, t_data	*target)
{
	int		i;
	if (!target)
		return ;
	i = 0;
	target->down = p_lstsize(target);
	target->up = p_lstsize(stack) - target->down;
	target = target->next;
	return (position(stack, target));
}

void	calculation_data(t_stack	*stack)
{
	position(stack->b, stack->b);
	position(stack->a, stack->a);
	a_min_max(stack);
}