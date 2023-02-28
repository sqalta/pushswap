/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:05:10 by spalta            #+#    #+#             */
/*   Updated: 2023/02/28 19:08:35 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void print_error(int i)
{
	if (i == 155)
		ft_printf("The argument is not an integer.");
	if (i == 1)
		ft_printf("The argument is not an integer.2147483647");
	if (i == 3)
		ft_printf("sort");
	exit(0);
}

t_list	*create_a(t_list *s_a, char **st, int ac)
{
	char **buff;
	t_list	*tmp;
	t_list	*ss;
	int	i;
	int	j;

	tmp = s_a;
	j = -1;
	i = 1;
	buff = ft_split(st[i], ' ');
	while (i < ac)
	{
		j = -1;
		while (buff[++j])
		{
			ss = ft_lstnew(buff[j]);
			ft_lstadd_back(&tmp, ss);
		}
		i++;
		free(buff);
		buff = ft_split(st[i], ' ');
	}
	s_a = tmp;
	s_a = s_a->next;
	return (s_a);
}

int	ct_integer(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '-' || str[i] == '+' ||
			(str[i] >= '0' && str[i] <= '9')))
				return (0);
	if ((str[i] == '-' || str[i] == '+') && !(str[++i]))
		return (0);
	i--;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0); // error message!
	}
	return (1);
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

t_data *convert_int(t_list *stack)
{
	t_data	*stack_a;
	t_data	*tmp;
	t_data	*ret;

	stack_a = ft_calloc(sizeof(t_data), 1);
	while (stack)
	{
		tmp = p_lstnew(p_atoi(stack->content));
		p_lstadd_back(&stack_a, tmp);
		stack = stack->next;
	}
	return (stack_a);
}

int	is_sort(t_data	*stack_a)
{
	int		book;
	t_data	*tmp;
	t_data	*tmp1;
	int		flag;

	flag = 0;
	tmp = stack_a;
	tmp1 = stack_a->next;
	while (tmp->next)
	{
		book = tmp->nbr;
		while (tmp1)
		{
			if (!(book < tmp1->nbr))
				flag = 1;
			tmp1 = tmp1->next;				
		}
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	if (!flag)
		print_error(3);
	return (1);
}

int ct_av(int ac, char **str)  
{
	t_list	*stack;
	t_list	*tmp;
	t_list	*t_stack;
	t_data	*stack_a;

	stack = malloc (sizeof(t_list));
	t_stack = create_a(stack, str, ac);
	tmp = stack;
	stack = stack->next;
	free(tmp);
	while (stack)
	{
		if (!(ct_integer(stack->content)))
			print_error(155);
		stack = stack->next;
	}
	stack_a = convert_int(t_stack);
	stack_a = stack_a->next;
	is_sort(stack_a);
	system ("leaks p_swap");
	return (1);
}