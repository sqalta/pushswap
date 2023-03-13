/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_small_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:47:42 by spalta            #+#    #+#             */
/*   Updated: 2023/03/13 06:31:32 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_small_sort(t_stack *stack)
{
	t_data	*tmp;
	int		diff;

	tmp = stack->a;
	diff = tmp->inx - tmp->next->inx;
	if (diff == 2)
		ra (stack, 1);
	else if (diff == 1)
	{
		if (tmp->inx == p_lstsize(stack->a) - 1)
			sa(stack);
		else
		{
			sa(stack);
			rra(stack, 1);
		}
	}
	else if (diff == -2)
	{
		rra(stack, 1);
		sa (stack);
	}
	else
		rra (stack, 1);
}
