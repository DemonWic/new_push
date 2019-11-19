/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:27:14 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 18:04:09 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H
# define FREE_A_B ft_memdel((void **)(&(ab.b))); ft_memdel((void **)(&(ab.b)));
# define CHECK_MINUS(x) if((x) < 0) {return (1);}
# define NUM_INTERVAL (sorted.bot - sorted.top)
# define DEL_STACKS_RETURN(x) ({del_stacks(x); return (0);})

# include "../f_checker/checker.h"

typedef struct	s_sorted
{
	int *sorted;
	int top;
	int bot;
	int flag;
}				t_sorted;

int				push_swap(int num, const char **args, int debug);
int				*pre_sort(t_stacks ab);
int				sort_stack(t_stacks *ab, int *sorted);
void			sort_a(t_stacks *ab, t_sorted sorted);
int				q_sort_stack(t_stacks *ab, t_sorted srtd, int main_med,
					int *flag);
int				prep_for_mini_sort(t_stacks *ab, t_sorted srtd, int med,
					int main_med);
int				mini_sort(t_stacks *ab, t_sorted sorted, int aorb, int flag);
int				insertion_sort(t_stacks *ab, t_sorted sorted);
int				pre_insort_a(t_stacks *ab, t_sorted sorted, int f);
int				pre_insort_b(t_stacks *ab, t_sorted sorted, int f);
int				find_elem_isort(t_stacks *ab, t_sorted sorted, int i);
int				check_stack_a(t_stacks *ab, t_sorted sorted, int i);
void			push_a_main_even(t_stacks *ab, t_sorted srtd, int med);
void			push_a_main_uneven(t_stacks *ab, t_sorted srtd, int med);
void			push_a_secondary_even(t_stacks *ab, t_sorted srtd, int med);
void			push_a_secondary_uneven(t_stacks *ab, t_sorted srtd, int med);
int				push_b_main_even(t_stacks *ab, t_sorted srtd, int med,
					int flag);
void			push_b_secondary_even(t_stacks *ab, t_sorted srtd, int med);
void			mini_b_1(t_stacks *ab, t_sorted sorted);
void			mini_a_1(t_stacks *ab, t_sorted sorted);
int				r_or_rr(t_stacks ab, int aorb, int med, int difference);
void			many_pa(t_stacks *ab, int num, int flag);
void			many_rra(t_stacks *ab, int num, int flag);
void			many_rrb(t_stacks *ab, int num, int flag);
void			many_ra(t_stacks *ab, int num, int flag);
void			many_rb(t_stacks *ab, int num, int flag);
t_stacks		*cpy_stacks(t_stacks ab);
void			del_stacks(t_stacks **ab);

#endif
