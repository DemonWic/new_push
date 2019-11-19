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

int			check_stack_a(t_stacks *ab, t_sorted sorted, int i)
{
	int j;
	int f;

	j = 0;
	f = 0;
	while (i >= sorted.top)
	{
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
	}
	many_rra(ab, j, 1);
	return (f);
}

static int	come_back_pre_sort(t_stacks *ab, int start, int *i, int *j)
{
	int f;

	f = 0;
	while (ab->a[ab->a_top] > ab->a[A_NEXT])
	{
		do_sa(ab, 1);
		f++;
		if (ab->a[ab->a_top] < ab->a[A_PREV] && A_PREV != start)
		{
			do_rra(ab, 1);
			*j -= 1;
			*i += 1;
			f++;
		}
	}
	return (f);
}

int			pre_insort_a(t_stacks *ab, t_sorted sorted, int f)
{
	const int	start = A_PREV;
	int			i;
	int			j;

	i = sorted.bot - 1;
	j = 0;
	while (i >= sorted.top)
	{
		CHECK_MINUS(f -= come_back_pre_sort(ab, start, &i, &j));
		if (check_stack_a(ab, sorted, i) == 0)
			break ;
		do_ra(ab, 1);
		j++;
		CHECK_MINUS(--f);
		i--;
	}
	j > (sorted.bot - sorted.top / 2) ? many_rra(ab, j, 1) :
	many_ra(ab, sorted.bot - sorted.top - j, 1);
	CHECK_MINUS(j > (sorted.bot - sorted.top / 2) ? f - j : f -
	sorted.bot - sorted.top - j);
	return (0);
}

int			find_elem_isort(t_stacks *ab, t_sorted sorted, int i)
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

int			pre_insort_b(t_stacks *ab, t_sorted sorted, int f)
{
	int i;

	i = sorted.top - 1;
	while (++i < sorted.bot)
	{
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
