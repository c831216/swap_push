/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:07:42 by csolomo           #+#    #+#             */
/*   Updated: 2018/09/26 10:07:45 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 1 */
void  check_sheet(t_all *all, char *line)
{
  			if (!ft_strcmp(line, "sa"))
				sa(all);
			else if (!ft_strcmp(line, "sb"))
				sb(all);
			else if (!ft_strcmp(line, "ss"))
				ss(all);
			else if (!ft_strcmp(line, "pa"))
				pa(all);
			else if (!ft_strcmp(line, "pb"))
				pb(all);
			else if (!ft_strcmp(line, "ra"))
				ra(all);
			else if (!ft_strcmp(line, "rb"))
				rb(all);
			else if (!ft_strcmp(line, "rr"))
				rr(all);
			else if (!ft_strcmp(line, "rra"))
				rra(all);
			else if (!ft_strcmp(line, "rrb"))
				rrb(all);
			else if (!ft_strcmp(line, "rrr"))
				rrr(all);
			// else
			// 	err();
			all->i = 0;
}
/* 2 */
void	ko_check(t_all *all)
{
	if (check_order(all))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
/* 3 */
void	store_dup_make(t_all *all, int ac, char **av)
{
	store_2d_array(ac, av, all);
	dup_check(all);
	make_int_array(all);
}
/* 4 */
void	if_2(t_all *all)
{
	/* if only 2 digits are passed then swap like this */
	sa(all);
	ft_putstr("sa\n");
}
/* 5 */
void	if_3(t_all *all)
{
	hi_low(all);
	if_three(all);
}
