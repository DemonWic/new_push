/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:49:36 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/17 16:49:39 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mini_a_1_sec_happening(t_stacks *ab, t_sorted sorted)
{
	if (ab->a[A_NEXT] == sorted.sorted[sorted.top] && ab->a_num > 2)
	{
		do_ra(ab, 0);
		ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
		do_rra(ab, 0);
	}
	if (sorted.sorted[sorted.top + 1] == ab->a[ab->a_top] && ab->a_num != 2)
		ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
}

void		mini_a_1(t_stacks *ab, t_sorted sorted)
{
	if (sorted.sorted[sorted.top] == ab->a[ab->a_top])
	{
		ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
		do_ra(ab, 0);
		do_sa(ab, 0);
		do_rra(ab, 0);
		if (sorted.sorted[sorted.top + 1] == ab->a[ab->a_top] && ab->a_num != 2)
			do_sa(ab, 0);
	}
	else if (sorted.sorted[sorted.top + 1] == ab->a[ab->a_top])
		mini_a_1_sec_happening(ab, sorted);
	else
	{
		if (ab->a[A_NEXT] == sorted.sorted[sorted.top])
		{
			do_ra(ab, 0);
			ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
			do_rra(ab, 0);
		}
	}
}

static void	mini_b_1_sec_happening(t_stacks *ab, t_sorted sorted)
{
	if (ab->b[B_NEXT] == sorted.sorted[sorted.top])
	{
		do_sb(ab, 0);
		many_pa(ab, 3, 0);
	}
	else
	{
		do_rb(ab, 0);
		do_sb(ab, 0);
		do_pa(ab, 0);
		do_rrb(ab, 0);
		many_pa(ab, 2, 0);
	}
}

void		mini_b_1(t_stacks *ab, t_sorted sorted)
{
	if (sorted.sorted[sorted.top] == ab->b[ab->b_top])
	{
		do_pa(ab, 0);
		if (sorted.sorted[sorted.top + 1] != ab->b[ab->b_top])
			do_sb(ab, 0);
		many_pa(ab, sorted.bot - sorted.top - 1, 0);
	}
	else if (sorted.sorted[sorted.top + 1] == ab->b[ab->b_top])
		mini_b_1_sec_happening(ab, sorted);
	else
	{
		do_rb(ab, 0);
		if (sorted.sorted[sorted.top] != ab->b[ab->b_top])
			do_sb(ab, 0);
		many_pa(ab, 2, 0);
		do_rrb(ab, 0);
		do_pa(ab, 0);
	}
}
