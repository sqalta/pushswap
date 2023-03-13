/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:45:51 by spalta            #+#    #+#             */
/*   Updated: 2023/03/14 02:49:13 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	find_rules(t_stack *stack, char *rul)
{
	if (!ft_strncmp(rul, "sa", 2))
		sa(stack);
	else if (!ft_strncmp(rul, "sb", 2))
		sb(stack);
	else if (!ft_strncmp(rul, "ss", 2))
		ss(stack);
	else if (!ft_strncmp(rul, "rra", 3))
		rra(stack);
	else if (!ft_strncmp(rul, "rrb", 3))
		rrb(stack);
	else if (!ft_strncmp(rul, "rrr", 3))
		rrr(stack);
	else if (!ft_strncmp(rul, "pa", 2))
		pa(stack);
	else if (!ft_strncmp(rul, "pb", 2))
		pb(stack);
	else if (!ft_strncmp(rul, "ra", 2))
		ra(stack);
	else if (!ft_strncmp(rul, "rb", 2))
		rb(stack);
	else if (!ft_strncmp(rul, "rr", 2))
		rr(stack);
	else
		return (0);
	return (1);
}

void	handle_input(t_stack *stack)
{
	char	*inp;

	inp = get_next_line(0);
	if (inp == NULL)
		return ;
	while (inp)
	{
		if (!find_rules(stack, inp))
			return ;
		free (inp);
		inp = get_next_line(0);
	}
}

int	is_sort(t_stack *stack)
{
	t_data	*tmp;

	tmp = stack->a;
	while (tmp->next)
	{
		if (tmp->nbr < tmp->next->nbr)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (ac >= 2)
	{
		if (ac == 2 || ft_strlen(av[1]) == 0)
			return (0);
		ct_av (ac, av, stack);
		index_stacka(stack);
		handle_input(stack);
		if (is_sort(stack))
			ft_printf("OK");
		else
			ft_printf("KO");
	}
	return (0);
}
