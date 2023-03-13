/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:57 by spalta            #+#    #+#             */
/*   Updated: 2023/03/13 02:43:16 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int i)
{
	write (2, "Error\n", 6);
	exit(0);
}

int	p_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + str[i++] - 48;
	if (!(result < 2147483647 && result > -2147483648))
		print_error(1);
	return ((int)result * sign);
}

void	print_list(t_data *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		ft_printf("%d\n",st->nbr);
		if (!st->next)
			break ;
		st = st->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (ac > 2)
	{
		ct_av (ac, av, stack);
		index_stacka(stack);
		start_sort(stack);
		print_list(stack->a);
	}
	return (0);
}
