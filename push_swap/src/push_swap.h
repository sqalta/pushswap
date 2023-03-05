#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../Libft/libft.h"
#include "../printf/ft_printf.h"
#include "../gnl/get_next_line.h"

typedef	struct	s_data{
	int	nbr;
	struct s_data *next;
}t_data;

typedef	struct	s_stack{
	t_data	*a;
	t_data	*b;
}t_stack;


void 	print_list(t_data *st);
void 	print_error(int i);
int 	ct_av(int ac, char **str, t_stack *game_stack);
int		p_atoi(const char *str);
t_data	*p_lstlast(t_data *lst);
void	p_lstadd_back(t_data **lst, t_data *new);
void	p_lstadd_front(t_data **lst, t_data *new);
int		p_lstsize(t_data *lst);
t_data	*p_lstnew(int nbr);
int		p_create_stackb(t_data *lst);
void	sa(t_stack	*stack);
void	sb(t_stack	*stack);
void	pa(t_stack	*stack);
void	pb(t_stack	*stack);
void	ra(t_stack *stack);
void	rb(t_stack	*stack);
void	rr(t_stack	*stack);
void	rra(t_stack	*stack);
void	rrb(t_stack	*stack);

#endif