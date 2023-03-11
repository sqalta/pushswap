/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:18:06 by spalta            #+#    #+#             */
/*   Updated: 2023/03/11 15:45:21 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_up_down(t_stack	*stack, t_data *position)
{
	int	mid;
	int len;
	int	target;

	len = p_lstsize(stack->b);
	mid = len / 2;
	target = len - p_lstsize(position);
	if (target > mid)
		return (-1);
	else if (target < mid)
		return (1);
	else
		return (0);
}

void	b_position(t_stack *stack, t_data	*target)
{
	t_data	*b;
	int		i;

	if (!target)
		return ;
	b = stack->b;
	i = 0;
	target->down = p_lstsize(target);
	target->up = p_lstsize(stack->b) - target->down;
	target = target->next;
	return (b_position(stack, target));
}
