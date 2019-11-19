/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:07:59 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/17 13:32:55 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	median(t_sorted srtd, int *med, int *main_med, int *flag)
{
	int num;

	if ((srtd.bot - srtd.top) % 2 == 1 && (srtd.bot - srtd.top) != 1)
		num = (srtd.bot - srtd.top) / 2 + srtd.top + 1;
	else
		num = (srtd.bot - srtd.top) / 2 + srtd.top;
	*med = srtd.sorted[num];
	if (*flag == 2)
	{
		*main_med = *med;
		*flag = 0;
	}
	if (srtd.bot - srtd.top <= 3)
	{
		*flag = 1;
		return (1);
	}
	return (0);
}

t_sorted	init_sorted(t_sorted srtd, int flag)
{
	static int count_recurs;

	if ((srtd.bot - srtd.top) % 2 == 0)
	{
		if (flag == 1)
			srtd.bot -= ((srtd.bot - srtd.top) / 2);
		else
			srtd.top += ((srtd.bot - srtd.top) / 2);
	}
	else
	{
		if (flag == 1)
			srtd.bot -= ((srtd.bot - srtd.top) / 2);
		else
			srtd.top += ((srtd.bot - srtd.top) / 2 + 1);
	}
	count_recurs++;
	srtd.flag = flag;
	return (srtd);
}

static int	push_stacks_main(t_stacks *ab, t_sorted srtd, int med, int *flag)
{
	if (srtd.flag == 1)
	{
		CHECK_ONE(push_b_main_even(ab, srtd, med, *flag));
	}
	else
	{
		if ((srtd.bot - srtd.top) % 2 == 0)
			push_a_main_even(ab, srtd, med);
		else
			push_a_main_uneven(ab, srtd, med);
	}
	return (0);
}

static void	push_stacks_second(t_stacks *ab, t_sorted srtd, int med)
{
	if (srtd.flag == 1)
		push_b_secondary_even(ab, srtd, med);
	else
	{
		if ((srtd.bot - srtd.top) % 2 == 0)
			push_a_secondary_even(ab, srtd, med);
		else
			push_a_secondary_uneven(ab, srtd, med);
	}
}

int			q_sort_stack(t_stacks *ab, t_sorted srtd, int main_med, int *flag)
{
	int med;

	if (insertion_sort(ab, srtd) == 1)
	{
		*flag = 1;
		return (0);
	}
	if (median(srtd, &med, &main_med, flag) == 1)
		return (prep_for_mini_sort(ab, srtd, med, main_med));
	if (med >= main_med)
	{
		CHECK_ONE(push_stacks_main(ab, srtd, med, flag));
	}
	else
		push_stacks_second(ab, srtd, med);
	q_sort_stack(ab, init_sorted(srtd, 1), main_med, flag);
	med == main_med ? *flag = 0 : 0;
	q_sort_stack(ab, init_sorted(srtd, 0), main_med, flag);
	return (0);
}
