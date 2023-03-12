/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:18:06 by spalta            #+#    #+#             */
/*   Updated: 2023/03/12 21:50:37 by spalta           ###   ########.fr       */
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

int	calculate_min_step(t_data *a, t_data *b) // u -> up / d -> down total 4 ihtimal var.
{
	int	ad_bd;
	int	au_bu;
	int	au_bd;
	int	ad_bu;

	if (b->down > a->down)
		ad_bd = b->down;
	else
		ad_bd = a->down;
	b->total_step[0] = ad_bd;
	if (b->up > a->up)
		au_bu = b->up;
	else
		au_bu = a->up;
	b->total_step[1] = au_bu;
	au_bd = a->up + b->down;
	b->total_step[2] = au_bd;
	ad_bu = a->down + b->up;
	b->total_step[3] = ad_bu;
	find_min_step(b);
	return (1);
}

int cntrl_min_max(t_data *a, t_data *a_next, t_data *b, t_stack	*stack)
{
	if (!a_next)
		a_next = stack->a;
	if (b->inx > stack->a->max || b->inx < stack->a->min)
		return (1);
	if (a->inx > a_next->inx)
		return (0);
	if (a->inx < b->inx && a_next->inx > b->inx)
	{
		if (a_next->inx == stack->a->inx)
			return (666);
		return (555);
	}
	return (0);
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
	while (i++ != len)
	{
		min_max = cntrl_min_max(a, a->next, b, stack);
		if (min_max == 1)
		{
			calculate_min_step(stack->min, b);
			b->target = stack->min;
			break;
		}
		else if(min_max == 555)
		{
			calculate_min_step(a->next, b);
			b->target = a->next;
			break;
		}
		else if (min_max == 666)
		{
			calculate_min_step(stack->a, b);
			b->target = stack->a;
		}
		a = a->next;
	}
	if (b->next)
		find_a_position(stack, b->next);
}

void	calculation_data(t_stack	*stack)
{
	position(stack->b, stack->b);
	position(stack->a, stack->a);
	a_min_max(stack);
	find_a_position(stack, stack->b);
}



