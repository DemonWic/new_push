/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_insort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:04:32 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/23 13:04:33 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_stack_a(t_stacks *ab, t_sorted sorted, int i)
{
	int j;
	int f;

	j = 0;
	f = 0;
	//	print_stack(*ab);
	while (i >= sorted.top)
	{
//				ft_printf("[%d] [%d]\n", ab->a[ab->a_top], sorted.sorted[i]);
		if (ab->a[ab->a_top] != sorted.sorted[i])
		{
			do_ra(ab, 1);
			j++;
			f++;
		}
		else
		{
			do_ra(ab, 1);
			j++;
		}
		i--;
		//				print_stack(*ab);
	}
	many_rra(ab, j, 1);
	return (f);
}

int	pre_insort_a(t_stacks *ab, t_sorted sorted, int f)
{
	const int start = A_PREV;
	int i;
	int j;

	i = sorted.bot - 1;
	j = 0;
//	print_stack(*ab);
	while (i >= sorted.top)
	{
		while (ab->a[ab->a_top] > ab->a[A_NEXT])
		{
			//			ft_printf("[%d] [%d]\n", ab->a[ab->a_top], ab->a[A_NEXT]);
			//			print_stack(*ab);
			do_sa(ab, 1);
			CHECK_MINUS(--f);
			if (ab->a[ab->a_top] < ab->a[A_PREV] && A_PREV != start)
			{
				do_rra(ab, 1);
				j--;
				i++;
				CHECK_MINUS(--f);
			}
			//			print_stack(*ab);
		}
		//		ft_printf("[%d] [%d]\n", ab->a[ab->a_top], ab->a[A_NEXT]);
//		print_stack(*ab);
		if (check_stack_a(ab, sorted, i) == 0)
			break ;
		do_ra(ab, 1);
		j++;
		CHECK_MINUS(--f);
//		print_stack(*ab);
		i--;
	}
	many_rra(ab, j, 1);
	CHECK_MINUS(f - j);
//	print_stack(*ab);
	return (0);
}

int		check_stack_b(t_stacks *ab, t_sorted sorted, int i, int *k)
{
	const int start_k = *k;
	int j;
	int f;

	j = 0;
	f = 0;

	many_rrb(ab, *k, 1);
	*k = 0;
	while (i < sorted.bot)
	{
		//		ft_printf("[%d] [%d]\n", ab->b[ab->b_top], sorted.sorted[i]);
		if (ab->b[ab->b_top] != sorted.sorted[i])
		{
			*k == 0 ? *k = j : 0;
			do_rb(ab, 1);
			j++;
			f++;
		}
		else
		{
			do_rb(ab, 1);
			j++;
		}
		i++;
		//		print_stack(*ab);
	}
	*k != 0 ? *k = j - *k : 0;
	start_k == 0 ? *k = 0 : 0;
	many_rrb(ab, j, 1);
	return (f);
}

int		find_elem_isort(t_stacks *ab, t_sorted sorted, int i)
{
	int r;
	int rr;

	r = 0;
	rr = 0;
	while (ab->b[ab->b_top] != sorted.sorted[i])
	{
		do_rb(ab, 1);
		r++;
	}
	many_rrb(ab, r, 1);
	while (ab->b[ab->b_top] != sorted.sorted[i])
	{
		do_rrb(ab, 1);
		rr++;
	}
	many_rb(ab, rr, 1);
	return (r < rr ? 0 : 1);
}

int		pre_insort_b(t_stacks *ab, t_sorted sorted, int f)
{
	int i;

	i = sorted.top - 1;
//	print_stack(*ab);
	while (++i < sorted.bot)
	{
//		ft_printf("%d\n", sorted.sorted[i]);
		if (find_elem_isort(ab, sorted, i) == 0)
			while (ab->a[ab->a_top] != sorted.sorted[i])
			{
				do_rb(ab, 1);
				CHECK_MINUS(--f);
			}
		else
			while (ab->a[ab->a_top] != sorted.sorted[i])
			{
				do_rrb(ab, 1);
				CHECK_MINUS(--f);
			}
		do_pa(ab, 1);
		CHECK_MINUS(--f);
	}
	return (0);
}