/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <csolomo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:47:02 by csolomo           #+#    #+#             */
/*   Updated: 2018/09/28 13:26:58 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <limits.h>

int check(int *array, int c, int n)
{
	int i;

	i = -1;
	while (++i < n)
		if (array[i] == c)
			return (0);
	return (1);
}

void check_dup(t_all *all)
{
	int i;

	i = -1;
	while (++i < all->size_a)
		if (check(all->int_stack_a, all->int_stack_a[i], i) == 0)
		{
			ft_putstr_fd("\e[31mError\n\e[0m", 2);
			exit(EXIT_FAILURE);
		}
}

int is_only_didgit(char *s)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(s))
		if (s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]))
		{
			ft_putstr_fd("\e[31mError\n\e[0m", 2);
			exit(EXIT_FAILURE);
		}
	i = -1;
	while (++i < (int)ft_strlen(s))
		if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]))
			return (0);
	return (1);
}

int check_asc(t_all *all)
{
	int i;

	i = -1;
	while (++i < all->size_a - 1)
		if (all->int_stack_a[i] > all->int_stack_a[i + 1])
			return (0);
	i = -1;
	return (1);
}

void free_stuff(t_all *all)
{
	if (all->args)
		ft_freearray_char(&all->args);
	//if (all->int_stack_a)
	//	free(all->int_stack_a);
	//if (all->int_stack_b)
		//free(all->int_stack_b);
	//free(all);
}

void print_stacks(t_all *all)
{
	fprintf(stderr, "\e[34mSize A = %d ", all->size_a);
	fprintf(stderr, "\e[31mSTACK A = ");
	for(int i =0; i < all->size_a;i++)
		fprintf(stderr, "%d ", all->int_stack_a[i]);
	fprintf(stderr, "\e[0m\n");
	fprintf(stderr, "\e[34mSize B = %d ", all->size_b);
	fprintf(stderr, "\e[32mSTACK B = ");
	for(int i =0; i < all->size_b;i++)
		fprintf(stderr, "%d ", all->int_stack_b[i]);
	fprintf(stderr, "\e[0m\n");
}

t_all *init_struct();
void fill_stacka(t_all *all);

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b =  tmp;
}

void sa(t_all *all)
{
	swap(&all->int_stack_a[0], &all->int_stack_a[1]);
}

void sb(t_all *all)
{
	swap(&all->int_stack_b[0], &all->int_stack_b[1]);
}

void ra(t_all *all)
{
	int i;
	int tmp;

	i = -1;
	tmp = all->int_stack_a[0];
	while (++i < all->size_a - 1)
		all->int_stack_a[i] = all->int_stack_a[i + 1];
	all->int_stack_a[i] = tmp;
}

void rb(t_all *all)
{
	int i;
	int tmp;

	i = -1;
	tmp = all->int_stack_b[0];
	while (++i < all->size_b -1)
		all->int_stack_b[i] = all->int_stack_b[i + 1];
	all->int_stack_b[i] = tmp;
}

void pb(t_all *all)
{
	if (all->size_a > 0)
	{
		all->int_stack_b--;
		all->size_b++;
		all->size_a--;
		*all->int_stack_b = all->int_stack_a[0];
		all->int_stack_a++;
	}
}

void pa(t_all *all)
{
	if (all->size_b > 0)
	{
		all->int_stack_a--;
		all->size_a++;
		all->size_b--;
		*all->int_stack_a = all->int_stack_b[0];
		all->int_stack_b++;
	}
}

void	rr(t_all *all)
{
	ra(all);
	rb(all);
}

void	ss(t_all *all)
{
	sa(all);
	sb(all);
}

void rra(t_all *all)
{
	int i;

	i = all->size_a;
	while (--i > 0)
		swap(&all->int_stack_a[i], &all->int_stack_a[i - 1]);

}

void rrb(t_all *all)
{
	int i;

	i = all->size_b;
	while (--i > 0)
		swap(&all->int_stack_b[i], &all->int_stack_b[i - 1]);

}

void rrr(t_all *all)
{
	rra(all);
	rrb(all);
}

void extra_moves(t_all *all, char *line)
{
	if (!ft_strcmp(line, "rr"))
				rr(all);
	else if (!ft_strcmp(line, "rra"))
		rra(all);
	else if (!ft_strcmp(line, "rrb"))
		rrb(all);
	else if (!ft_strcmp(line, "rrr"))
		rrr(all);
	else
	{
		ft_putstr_fd("\e[31mError\n", 2);
		exit(EXIT_FAILURE);
	}
}

void check_sheet(t_all *all, char *line)
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
	else
		extra_moves(all, line);
}

void	ft_freearray_char(char ***array)
{
	int i;

	i = 0;
	while ((*array)[i] != NULL)
	{
	free((*array)[i]);
		i++;
	}
	free(*array);
}

int	ft_arrsize(char **arr)
{
	int len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}

char	**arr_join(char **arr1, char **arr2)
{
	int		i;
	int		j;
	int		arr_size;
	char	**strarr;

	i = -1;
	arr_size = ft_arrsize(arr1) + ft_arrsize(arr2);
	if (!(strarr = (char **)malloc(sizeof(char *) * arr_size + 1)))
		return (NULL);
	while (arr1[++i])
		strarr[i] = ft_strdup(arr1[i]);
	ft_freearray_char(&arr1);
	j = 0;
	while (arr2[j] != NULL)
	{
		strarr[i + j] = ft_strdup(arr2[j]);
		j++;
	}
	ft_freearray_char(&arr2);
	strarr[j + i] = NULL;
	return (strarr);
}

char	**join_args(char **av)
{
	int		i;
	char	**array;
	char	**split;

	i = -1;
	array = (char **)malloc(sizeof(char *));
	*array = NULL;
	while (av[++i] != NULL)
	{
		if (!ft_strcmp(av[i], "-v") || !ft_strcmp(av[i], "-c") ||
		!ft_strcmp(av[i], "-d"))
			continue ;
		split = ft_strsplit(av[i], ' ');
		array = arr_join(array, split);
	}
	return (array);
}

void error_check(t_all *all)
{
	int i;

	i = -1;
	while (all->args[++i])
	{
		if (!is_only_didgit(all->args[i]))
		{
			ft_freearray_char(&all->args);
			free(all);
			ft_putstr_fd("\e[31mError\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

////////////////////////////////////  MAIN  ///////////////////////////////////

int			main(int ac, char **av)
{

	(void)ac;
	t_all	*all;

	all = init_struct();
	all->args = join_args(av + 1);
	error_check(all);
	all->size = ft_arrsize(all->args);
	all->size_a = all->size;
	fill_stacka(all);
	// print_stacks(all);
	check_dup(all);
	if (check_asc(all))
		return(0);
	while (get_next_line(0, &all->line) > 0)
	{
		check_sheet(all, all->line);
		// print_stacks(all);
		if (all->line)
			ft_strdel(&all->line);
	}
	if (check_asc(all))
		ft_putstr_fd("\e[32mOK\n\e[0m", 2);
	else
		ft_putstr_fd("\e[31mKO\n\e[0m", 2);
	free_stuff(all);
	return (0);
}


////////////////////////////////////////////////////////////////////////////////

t_all *init_struct(void)
{
	t_all *all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
	{
		fprintf(stderr, "YOU SUCK\n");
		exit(EXIT_FAILURE);
	}
	all->int_stack_a = 0;
	all->int_stack_b = 0;
	all->args = NULL;
	all->size = 0;
	all->size_a = 0;
	all->size_b = 0;
	return (all);
}

void fill_stacka(t_all *all)
{
	int i;

	i = -1;
	all->int_stack_a = (int *)malloc(sizeof(int ) * all->size);
	all->int_stack_b = (int *)malloc(sizeof(int ) * all->size);
	while (++i < all->size)
	{
		all->int_stack_a[i] = ft_atoi(all->args[i]);
		all->int_stack_b++;
	}
	all->int_stack_b++;
}