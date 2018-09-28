/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:07:24 by csolomo           #+#    #+#             */
/*   Updated: 2018/09/26 10:07:29 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 1 */
void rb(t_all *all)
{
  printf("%d\n", all->int_stack_b[0]);
  int *tmp = (int *)malloc(sizeof(int) * all->b_counter + 1);
  int i = 0;
  while (i < all->b_counter)
  {
    tmp[i + 1] = all->int_stack_b[i];
    i++;
  }
  tmp[0] = all->int_stack_b[all->b_counter - 1];
  i = 0;
  while (i < all->b_counter)
  {
    all->int_stack_b[i] = tmp[i];
    i++;
  }
}
/* 2 */
void rra(t_all *all)
{
  int *tmp = (int *)malloc(sizeof(int) * all->a_counter + 1);
  int i = 0;
  while (i < all->a_counter - 1)
  {
    tmp[i + 1] = all->int_stack_a[i];
    i++;
  }
  tmp[0] = all->int_stack_a[all->a_counter - 1];
  i = 0;
  while (i < all->a_counter)
  {
    all->int_stack_a[i] = tmp[i];
    i++;
  }
}
/* 3 */
void rrb(t_all *all)
{
  int *tmp = (int *)malloc(sizeof(int) * all->b_counter + 1);
  int i = 0;
  while (i < all->b_counter - 1)
  {
    tmp[i + 1] = all->int_stack_b[i];
    i++;
  }
  tmp[0] = all->int_stack_b[all->b_counter - 1];
  i = 0;
  while (i < all->b_counter)
  {
    all->int_stack_b[i] = tmp[i];
    i++;
  }
}
/* 4 */
void	if_three(t_all *all)
{
  int i = 0;
	if (all->a_counter == 3)
	{
		if (all->int_stack_a[i] == all->high && all->int_stack_a[i+1] == all->mid)
		{
			sa(all);
			ft_putstr("sa\n");
			rra(all);
			ft_putstr("rra\n");
		}
		else if (all->int_stack_a[i] == all->high && all->int_stack_a[i+1] == all->low)
		{
			ra(all);
			ft_putstr("ra\n");
		}
    else if (all->int_stack_a[i] == all->mid && all->int_stack_a[i+1] == all->low)
		{
			sa(all);
			ft_putstr("sa\n");
		}
    else if (all->int_stack_a[i] == all->mid && all->int_stack_a[i+1] == all->high)
		{
			rra(all);
			ft_putstr("rra\n");
		}

		else if (all->int_stack_a[i] == all->low && all->int_stack_a[i+1] == all->high)
		{
			sa(all);
			ft_putstr("sa\n");
			ra(all);
			ft_putstr("ra\n");
		}
	}
}
/* 5 */
void	hi_low(t_all *all)
{
	int i = 0;
	all->low = 0;
	all->mid = 0;
	all->high = 0;
	if (all->a_counter == 3)
	{
		if (all->int_stack_a[i] > all->int_stack_a[i+1] && all->int_stack_a[i] > all->int_stack_a[i+2])
    {
			all->high = all->int_stack_a[i];
      if (all->int_stack_a[i+1] < all->int_stack_a[+2])
      {
        all->low = all->int_stack_a[i+1];
        all->mid = all->int_stack_a[i+2];
      }
      else
      {
        all->mid = all->int_stack_a[i+1];
        all->low = all->int_stack_a[i+2];
      }
    }
		if (all->int_stack_a[i] > all->int_stack_a[i+1] && all->int_stack_a[i] < all->int_stack_a[i+2])
    {
  		all->mid = all->int_stack_a[i];
      if (all->int_stack_a[i+1] < all->int_stack_a[+2])
      {
        all->low = all->int_stack_a[i+1];
        all->high = all->int_stack_a[i+2];
      }
      else
      {
        all->high = all->int_stack_a[i+1];
        all->low = all->int_stack_a[i+2];
      }
    }
    if (all->int_stack_a[i] < all->int_stack_a[i+1] && all->int_stack_a[i] > all->int_stack_a[i+2])
    {
			all->mid = all->int_stack_a[i];
      if (all->int_stack_a[i+1] < all->int_stack_a[+2])
      {
        all->low = all->int_stack_a[i+1];
        all->high = all->int_stack_a[i+2];
      }
      else
      {
        all->high = all->int_stack_a[i+1];
        all->low = all->int_stack_a[i+2];
      }
    }
    if (all->int_stack_a[i] < all->int_stack_a[i+1] && all->int_stack_a[i] < all->int_stack_a[i+2])
    {
  		all->low = all->int_stack_a[i];
      if (all->int_stack_a[i+1] < all->int_stack_a[+2])
      {
        all->mid = all->int_stack_a[i+1];
        all->high = all->int_stack_a[i+2];
      }
      else
      {
        all->high = all->int_stack_a[i+1];
        all->mid = all->int_stack_a[i+2];
      }
    }
	}
}
