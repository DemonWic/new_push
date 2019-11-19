/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:52:18 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/17 13:52:24 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mini_a_0(t_stacks *ab, t_sorted sorted)
{
	static int num;

	if (++num > 1)
		return (1);
	if (sorted.sorted[sorted.top] == ab->a[ab->a_top])
	{
		do_ra(ab, 0);
		if (sorted.sorted[sorted.top + 1] == ab->a[ab->a_top] &&
				ab->a_num != 2)
			ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
	}
	else if (sorted.sorted[sorted.top + 1] == ab->a[ab->a_top])
	{
		if (ab->a[A_NEXT] == sorted.sorted[sorted.top] && ab->a_num > 2)
			do_rra(ab, 0);
		else if (ab->a_num > 2)
			ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
	}
	else
	{
		ab->a[A_NEXT] == sorted.sorted[sorted.top] ? do_rra(ab, 0) : 0;
		if (sorted.sorted[sorted.top + 1] == ab->a[ab->a_top])
			ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
	}
	return (0);
}

static int	mini_b_0(t_stacks *ab, t_sorted sorted)
{
	static int num;

	if (++num > 1)
		return (1);
	if (sorted.sorted[sorted.top] == ab->b[ab->b_top])
	{
		do_pa(ab, 0);
		sorted.sorted[sorted.top + 1] != ab->b[ab->b_top] ? do_sb(ab, 0) : 0;
		many_pa(ab, 2, 0);
	}
	else if (sorted.sorted[sorted.top + 1] == ab->b[ab->b_top])
	{
		ab->b[B_NEXT] == sorted.sorted[sorted.top] ? do_sb(ab, 0) : 0;
		ab->b_num > 2 ? do_rrb(ab, 0) : 0;
		many_pa(ab, ab->b_num, 0);
	}
	else
	{
		ab->b[B_NEXT] != sorted.sorted[sorted.top] ?
		do_rrb(ab, 0) : do_sb(ab, 0);
		do_pa(ab, 0);
		sorted.sorted[sorted.top + 1] != ab->b[ab->b_top] ? do_sb(ab, 0) : 0;
		many_pa(ab, 2, 0);
	}
	return (0);
}

int			mini_sort(t_stacks *ab, t_sorted sorted, int aorb, int flag)
{
	if (sorted.bot - sorted.top < 3)
	{
		if (aorb == 1 && sorted.bot - sorted.top == 1)
			do_pa(ab, 0);
		else if (aorb == 1 && sorted.bot - sorted.top == 2)
		{
			if (ab->b[ab->b_top] != sorted.sorted[sorted.top])
				do_sb(ab, 0);
			many_pa(ab, 2, 0);
		}
		else if (aorb == 0 && sorted.bot - sorted.top == 2)
		{
			if (ab->a[ab->a_top] == sorted.sorted[sorted.top])
				ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
		}
	}
	else if (aorb == 0 && flag == 0)
		mini_a_0(ab, sorted);
	else if (aorb == 1 && flag == 0)
		mini_b_0(ab, sorted);
	else if (aorb == 0 && flag == 1)
		mini_a_1(ab, sorted);
	else if (aorb == 1 && flag == 1)
		mini_b_1(ab, sorted);
	return (0);
}

int			prep_for_mini_sort(t_stacks *ab, t_sorted srtd, int med,
		int main_med)
{
	if (med >= main_med)
		if (ab->a_num <= 3 && srtd.flag == 1)
			mini_sort(ab, srtd, 0, 0);
		else if (srtd.flag == 0)
			mini_sort(ab, srtd, 1, 1);
		else
			mini_sort(ab, srtd, 0, 1);
	else
	{
		if (ab->b_num <= 3 && srtd.flag == 0)
			mini_sort(ab, srtd, 1, 0);
		else if (srtd.flag == 0)
			mini_sort(ab, srtd, 1, 1);
		else if (srtd.flag == 1)
			mini_sort(ab, srtd, 0, 1);
	}
	return (0);
}
