/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:01:37 by spalta            #+#    #+#             */
/*   Updated: 2023/03/06 21:39:35 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	mix_index(t_data *stack)
{
	int	inx;
	
	inx = 0;
	while (stack)
	{
		stack->inx = inx++;
		stack = stack->next;
	}
}

void	sort_stacka(t_stack	*stack)
{
	t_data	*tmp1;
	t_data	*tmp2;
	int		swap;

	tmp1 = stack->a->next;
	tmp2 = stack->a;
	mix_index(stack->a);
	while (stack->a->next)
	{
		while (tmp1)
		{
			if ((stack->a->nbr > tmp1->nbr) && (stack->a->inx < tmp1->nbr))
			{
				swap = stack->a->inx;
				stack->a->inx = tmp1->inx;
				tmp1->inx = swap;
			}
			getchar();
			print_list(stack->a);
			tmp1 = tmp1->next;
		}
		stack->a = stack->a->next;
		tmp1 = stack->a;
	}
	stack->a = tmp2;
	print_list(stack->a);
}