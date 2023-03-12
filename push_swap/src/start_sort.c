/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:32:36 by spalta            #+#    #+#             */
/*   Updated: 2023/03/12 19:12:55 by spalta           ###   ########.fr       */
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
		if (stack->a->push_flag == 1)
			ra(stack);
		else
			pb(stack);
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
	f_next = m_stack->a;
	while (f_next->inx != find->inx)
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

t_data	*find_start_list(t_stack	*stack, int	*len) //listenin nerede olduğunu bulma.
{
	t_data	*a;
	int		i;
	int		big;

	a = stack->a;
	i = 0;
	big = 0;
	while (i < p_lstsize(stack->a))
	{
		if (len[i] > big)
			big = len[i];
		i++;
	}
	i = 0;
	while (i < p_lstsize(stack->a))
	{
		if (len[i] == big)
			break;
		i++;
	}
	big = 0;
	while (i > 0)
	{
		i--;
		a = a->next;
	}
	return (a);
}

void	mark_stack_a(t_stack *stack, t_data *first_a)
{
	t_data	*f_next;
	int		len;
	int		tmp_find;
	
	tmp_find = first_a->inx;
	f_next = first_a->next;
	len = 0;
	first_a->push_flag = 1;
	while (f_next)
	{
		if (tmp_find < f_next->inx)
		{
			f_next->push_flag = 1;
			tmp_find = f_next->inx;
		}
		f_next = f_next->next;
	}
	f_next = stack->a;
	while (f_next->inx != first_a->inx)
	{
		if (tmp_find < f_next->inx)
		{
			f_next->push_flag = 1;
			tmp_find = f_next->inx;
		}
		f_next = f_next->next;
	}
}

void	find_big_a(t_stack	*stack) //listede en uzun artarak giden listeyi oluşturuyorum. 2 boyutlu arrayda her bir sayının artarak ne kadar gidebildiğine bakıyorum.
{
	t_data	*st;
	t_data	*first_a;
	int		i;
	int		*len;

	len = malloc(sizeof(int) * p_lstsize(stack->a));
	st = stack->a;
	i = 0;
	while (st)
	{
		len[i++] = check_sort_len(stack, st);
		st = st->next;
	}
	first_a = find_start_list(stack, len); //oluşturacağım stacka için list yapıma bir integer koyup b stackine göndermeyeceklerimi işaretleyeceğim.!
	mark_stack_a(stack, first_a);
	/*while (stack->a)
	{
		getchar();
		ft_printf ("%d->", stack->a->nbr);
		ft_printf ("%d\n", stack->a->push_flag);
		stack->a = stack->a->next;
	}*/
}

void	start_sort(t_stack	*stack) //!!Leaks!!
{
	find_big_a(stack);
	begin_stacka(stack);
	calculation_data(stack);
	start_push(stack);
	calculation_data(stack);
	start_push(stack);
	calculation_data(stack);
	start_push(stack);
	exit(0);
	while (stack->a)
	{
		getchar();
		ft_printf("up->%ddown->%d", stack->a->up, stack->a->down);
		stack->a = stack->a->next;
	}
}