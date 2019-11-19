/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:58:43 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/19 10:58:45 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_main_even(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	const int	rorrr = r_or_rr(*ab, 1, med, difference);
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab, 0);
		}
		else
		{
			f++;
			if (rorrr == 0)
				do_rb(ab, 0);
			else
				do_rrb(ab, 0);
		}
//		print_stack(*ab);
	}
	if (rorrr == 0)
		many_rrb(ab, f, 0);
	else
		many_rb(ab, f, 0);
}

void	push_a_main_uneven(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top + 1) / 2;
	const int	rorrr = r_or_rr(*ab, 1, med, difference);
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab, 0);
		}
		else
		{
			f++;
			if (rorrr == 0)
				do_rb(ab, 0);
			else
				do_rrb(ab, 0);
		}
//		print_stack(*ab);
	}
	if (rorrr == 0)
		many_rrb(ab, f, 0);
	else
		many_rb(ab, f, 0);
}

void	push_a_secondary_even(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	const int	rorrr = r_or_rr(*ab, 1, med, difference);
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab, 0);
		}
		else
		{
			f++;
			if (rorrr == 0)
				do_rb(ab, 0);
			else
				do_rrb(ab, 0);
		}
//		print_stack(*ab);
	}
	if (rorrr == 0 && ab->b_num > 6)
		many_rrb(ab, f, 0);
	else if (ab->b_num > 6)
		many_rb(ab, f, 0);
}

void	push_a_secondary_uneven(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top + 1) / 2;
	const int	rorrr = r_or_rr(*ab, 1, med, difference);
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab, 0);
		}
		else
		{
			f++;
			if (rorrr == 0)
				do_rb(ab, 0);
			else
				do_rrb(ab, 0);
		}
//		print_stack(*ab);
	}
	if (rorrr == 0 && ab->b_num > 3)
		many_rrb(ab, f, 0);
	else if (ab->b_num > 3)
		many_rb(ab, f, 0);
}