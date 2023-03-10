#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../Libft/libft.h"
#include "../printf/ft_printf.h"
#include "../gnl/get_next_line.h"

typedef	struct	s_data{
	int	nbr;
	int	inx;
	int	push_flag;
	struct s_data *next;
	struct s_data *back;
}t_data;

typedef	struct	s_stack{
	t_data	*a;
	t_data	*b;
	t_data	*a_cpy;
}t_stack;

typedef	struct	s_statistic{
	int	deviation;     
}t_statistic;


void 	print_list(t_data *st);
void 	print_error(int i);
int 	ct_av(int ac, char **str, t_stack *game_stack);
int		p_atoi(const char *str);
t_data	*p_lstnew(int nbr, int inx);
t_data	*p_lstlast(t_data *lst);
void	p_lstadd_back(t_data **lst, t_data *new);
void	p_lstadd_front(t_data **lst, t_data *new);
int		p_lstsize(t_data *lst);
int 	p_addition_inx(t_data	*lst);
int		p_create_stackb(t_data *lst);
int		st_deviation(t_data	*s);
void	index_stacka(t_stack	*stack);
void	start_sort(t_stack	*stack);
void 	p_s(t_stack *stack);
void	sa(t_stack	*stack);
void	sb(t_stack	*stack);
void	ss(t_stack	*stack);
void	pa(t_stack	*stack);
void	pb(t_stack	*stack);
void	ra(t_stack *stack);
void	rb(t_stack	*stack);
void	rr(t_stack	*stack);
void	rra(t_stack	*stack);
void	rrb(t_stack	*stack);
void	rrr(t_stack	*stack);

#endif