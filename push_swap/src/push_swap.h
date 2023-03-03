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

void 	print_error(int i);
int 	ct_av(int ac, char **str);
int		p_atoi(const char *str);
t_data	*p_lstlast(t_data *lst);
void	p_lstadd_back(t_data **lst, t_data *new);
void	p_lstadd_front(t_data **lst, t_data *new);
t_data	*p_lstnew(int nbr);

#endif