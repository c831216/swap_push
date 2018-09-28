
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "struct.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_all
{
	int 		*int_stack_a;
	int			*int_stack_b;
	char		**args;
	int			size;
	char		*line;
	int			size_a;
	int			size_b;
	int			*sorted;
	
	char		**stack;
	char		**stack_a;
	char 		**tmp;
	int			k;
	int 		m;
	int			a_counter;
	int			b_counter;
	int 		i; 
	int 		j;
	int			b;
	int 		count;
	int			a_stack_size;
	int 		low;
	int 		mid;
	int 		high;
}						t_all;

// int				error_free(int ac, char **av);
// void			store_2d_array(int ac, char **av, t_all *all);
// void			dup_check(t_all *all);
// void			make_int_array(t_all *all);
// void			print_stacks(t_all *all);
// int				check_order(t_all *all);
// void			sa(t_all *all);
// void			sb(t_all *all);
// void			pa(t_all *all);
// void			pb(t_all *all);
// void			ra(t_all *all);
// void			rb(t_all *all);
// void			rra(t_all *all);
// void			rrb(t_all *all);
// void			if_three(t_all *all);
// void			hi_low(t_all *all);
// void			stack_rank(t_all *all);
// void			ss(t_all *all);
// void			rr(t_all *all);
// void			rrr(t_all *all);
// void			check_sheet(t_all *all, char *line);
// void			err();
// void			ko_check(t_all *all);
// void			store_dup_make(t_all *all, int ac, char **av);
// void			if_2(t_all *all);
// void			if_3(t_all *all);
// void			if_4(t_all *all);
// void			if_5(t_all *all);
// void			ft_freearray_int(int ***array);
void			ft_freearray_char(char ***array);
#endif
