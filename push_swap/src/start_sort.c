/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:32:36 by spalta            #+#    #+#             */
/*   Updated: 2023/03/08 19:53:52 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_stacka(t_stack *stack)
{
	int	min;
	int max;

	min = 1;
	max = p_lstsize(stack->a_cpy);
	while (p_lstsize(stack->a) > 2)
	{
		if (!(stack->a->inx == min || stack->a->inx == max))
			pb(stack);
		else
			ra(stack);
	}
	ft_printf("--->A\n");
	print_list(stack->a);
}

void	start_sort(t_stack	*stack)
{
	begin_stacka(stack);
	
}