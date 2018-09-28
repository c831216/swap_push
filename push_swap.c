/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:08:14 by csolomo           #+#    #+#             */
/*   Updated: 2018/09/26 10:32:14 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	store_2d_array(ac, av, all);
	dup_check(all);
	make_int_array(all);
	if (ac > 1 && (check_order(all) != 1))
	{
		stack_rank(all);
		if (all->a_counter == 2)
			if_2(all);
		if (all->a_counter == 3)
			if_3(all);
		if (all->a_counter == 4)
			if_4(all);
		if (all->a_counter == 5)
			if_5(all);
	}
	free(all);
	return (0);
}
