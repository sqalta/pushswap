/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:18:06 by spalta            #+#    #+#             */
/*   Updated: 2023/03/11 22:56:45 by spalta           ###   ########.fr       */
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
		{
			a->is_min = 1;
			stack->min = a;
		}
		if (a->inx == max)
		{
			a->is_max = 1;
			stack->max = a;
		}
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
	stack->a->min = min;
	stack->a->max = max;
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

int	calculate_min_step(t_data *a, t_data *b) // + yukarı - aşağı
{
	int	up_step;
	int down_step;
	
	ft_printf("%d->%d\n", a->inx, b->inx);
	if (a->down > b->down)
		down_step = a->down;
	else
		down_step = b->down;
	if (a->up > b->up)
		up_step = a->up;
	else
		up_step = b->up;
	if (up_step < down_step)
		b->total_step = up_step;
	else
		b->total_step = -1 * down_step;
	if (!b->next)
		return (0);
	return (1);
}

int cntrl_min_max(t_data *a, t_data *a_next, t_data *b)
{
	if (b->inx > a->max)
		return (1);
	if (b->inx < a->min)
		return (1);
	if (a->is_min == 1 && a_next->is_max == 1)
		if (b->inx > a->min && b->inx < a->max)
			return (0);
	return (155);
}

void	find_a_position(t_stack *stack, t_data *b)
{
	t_data	*a;
	int		min_max;
	int		len;
	int		i;
	
	len = p_lstsize(stack->a);
	a = stack->a;
	i = 0;
	min_max = cntrl_min_max(a, a->next, b);
	if (min_max == 1)
		calculate_min_step(stack->min, b);
	else
	{
		while (i <= len)
		{
			if (cntrl_min_max(a, a->next, b))
				if (a->next && a->inx < b->inx && a->next->inx > b->inx)
					break;
			a = a->next;
		}
	if (!calculate_min_step(a, b))
		return ;
	}
	find_a_position(stack, b->next);
}

void	calculation_data(t_stack	*stack)
{
	position(stack->b, stack->b);
	position(stack->a, stack->a);
	a_min_max(stack);
	find_a_position(stack, stack->b);
	print_list(stack->b);
	while (stack->b)
	{
		getchar();
		ft_printf("->totalstep%d\n", stack->b->total_step);
		stack->b = stack->b->next;
	}
}



