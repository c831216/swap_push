/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:07:51 by csolomo           #+#    #+#             */
/*   Updated: 2018/09/26 10:07:54 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 1 */
void	if_4(t_all *all)
{
	while (all->b_counter < 1)/* pb lowest 2 then sort a and pa */
	{
		if (all->int_stack_a[0] < 2)
		{
			pb(all);
			ft_putstr("pb\n");
		}
		else
		{
			ra(all);
			ft_putstr("ra\n");
		}
	}
	hi_low(all);
	if_three(all);
	pa(all);
	ft_putstr("pa\n");
}
/* 2 */
void	if_5(t_all *all)
{
	while (all->b_counter < 2)
	{
		if (all->int_stack_a[0] < 3)
		{
			pb(all);
			ft_putstr("pb\n");
		}
		else
		{
			ra(all);
			ft_putstr("ra\n");
		}
	}
	hi_low(all);
	if_three(all);
	while (all->a_counter < 5)
	{
		if (all->int_stack_b[0] < all->int_stack_b[1])
		{
			sb(all);
			ft_putstr("sb\n");
			pa(all);
			ft_putstr("pa\n");
			pa(all);
			ft_putstr("pa\n");
		}
		else
		{
			pa(all);
			ft_putstr("pa\n");
			pa(all);
			ft_putstr("pa\n");
		}
	}
}
/* 3 */

/* 4 */

/* 5 */
