/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:32:36 by spalta            #+#    #+#             */
/*   Updated: 2023/03/10 16:39:04 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_stacka(t_stack *stack)
{
	int	len;
	int	i;

	len = p_lstsize(stack->a);
	i = 0;
	while (i < len)
	{
		if (stack->a->inx % 2 == 0)
			pb(stack);
		else
			ra(stack);
		i++;
	}
}

int	check_sort_len(t_stack	*m_stack, t_data *find)
{
	t_data	*f_next;
	int		len;
	int		tmp_find;

	tmp_find = find->inx;
	if (!find->next)
		return (0); // başa getirebilirsin!
	else
		f_next = find->next;
	len = 0;
	while (f_next)
	{
		if (tmp_find < f_next->inx)
		{
			len++;
			tmp_find = f_next->inx;
		}
		f_next = f_next->next;
	}
	return (len);
}

void	find_big_a(t_stack	*stack)
{
	t_data	*st;
	int		i;
	int		*len;

	len = malloc(sizeof(int) * p_lstsize(stack->a));
	st = stack->a;
	i = 0;
	while (st)
	{
		len[i++] = check_sort_len(stack, st);
		getchar();
		ft_printf("%d", len[i - 1]);
		st = st->next;
	}
}

void	start_sort(t_stack	*stack)
{
	//begin_stacka(stack);
	find_big_a(stack);
	exit(0);
	print_list(stack->a);
}