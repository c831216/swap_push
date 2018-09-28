/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:07:16 by csolomo           #+#    #+#             */
/*   Updated: 2018/09/26 10:07:19 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 1 */
void sa(t_all *all)
{
  if (all->a_counter > 1)
  {
    int tmp;
    tmp = all->int_stack_a[0];
    all->int_stack_a[0] = all->int_stack_a[1];
    all->int_stack_a[1] = tmp;
  }
}
/* 2 */
void sb(t_all *all)
{
  if (all->b_counter > 1)
  {
    int tmp;
    tmp = all->int_stack_b[0];
    all->int_stack_b[0] = all->int_stack_b[1];
    all->int_stack_b[1] = tmp;
  }
}
/* 3 */
void pa(t_all *all)
{
  if (all->b_counter > 0)
  {
    int *tmp = (int *)malloc(sizeof(int) * all->a_counter);
    int i = 0;
    while (i < all->a_counter)
    {
      tmp[i + 1] = all->int_stack_a[i];
      i++;
    }
    tmp[0] = all->int_stack_b[0];
    all->b_counter--;
    all->a_counter++;
    i = 0;
    while (i <= all->a_counter)
    {
      all->int_stack_a[i] = tmp[i];
      i++;
    }

    i = 0;
    while (i < all->b_counter)
    {
      all->int_stack_b[i] = all->int_stack_b[i + 1];
      ++i;
    }
    all->int_stack_b[i + 1] = '\0';
  }
}
/* 4 */
void pb(t_all *all)
{
  if (all->a_counter > 0)
  {
    int *tmp = (int *)malloc(sizeof(int) * all->b_counter + 1);
    int i = 0;
    while (i < all->b_counter)
    {
      tmp[i + 1] = all->int_stack_b[i];
      i++;
    }
    tmp[0] = all->int_stack_a[0];
    all->a_counter--;
    all->b_counter++;
    i = 0;
    while (i <= all->b_counter)
    {
      all->int_stack_b[i] = tmp[i];
      i++;
    }
    i = 0;
    while (i < all->a_counter)
    {
      all->int_stack_a[i] = all->int_stack_a[i + 1];
      ++i;
    }
    all->int_stack_a[i + 1] = '\0';
  }
}
/* 5 */
void ra(t_all *all)
{
  int tmp;
  int i;

  tmp = all->int_stack_a[0];

  i = 0;
  while (i < all->a_counter - 1)
  {
    all->int_stack_a[i] = all->int_stack_a[i+1];
    i++;
  }
  all->int_stack_a[i] = tmp; 
}

