/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:01:56 by spalta            #+#    #+#             */
/*   Updated: 2023/03/11 14:59:56 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	st_variance(t_data	*s, int	avrg, int len)
{
	int	variance;
	int	t_variance;
	int res;
    int	i;

	variance = 0;
	t_variance = 0;
	while (s->next)
	{
		variance = (avrg - s->inx);
		variance *= variance;
		t_variance += variance;
		s = s->next;
	}
	t_variance = (t_variance / (len - 1));
	i = 1;
	res = t_variance;
    while ((res - t_variance / res) > i) {
        res = (res + t_variance / res) / 2;
    }
    return (res);
}

int	st_deviation(t_data	*s) // gelen listin uzunluğuna göre hesaplama yapılmayabilir ekle!;
{
	int	len;
	int	avrg;
	int	variance;


	len = p_lstsize(s);
	avrg = p_addition_inx(s) / len;
	variance = st_variance(s, avrg, len);
	ft_printf("->>%d", variance);
	return (1);
}