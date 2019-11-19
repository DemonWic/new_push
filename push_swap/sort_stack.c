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

static int mediana(t_sorted srtd, int *mediana, int *main_med, int *flag)
{
	int num;

	if ((srtd.bot - srtd.top) % 2 == 1 && (srtd.bot - srtd.top) != 1)
		num = (srtd.bot - srtd.top) / 2 + srtd.top + 1;
	else
		num = (srtd.bot - srtd.top) / 2 + srtd.top;
	*mediana = srtd.sorted[num];
    if (*flag == 2)
    {
        *main_med = *mediana;
        *flag = 0;
    }
	if (srtd.bot - srtd.top <= 3)
	{
		*flag = 1;
		return (1);
	}
	return (0);
}

t_sorted init_sorted(t_sorted srtd, int med, int main_med, int flag)
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

int 	q_sort_stack(t_stacks *ab, t_sorted srtd, int main_med, int *flag)
{
	int med;

	if (insertion_sort(ab, srtd, srtd.flag) == 1)
		return (0);
//	print_stack(*ab);
	if (mediana(srtd, &med, &main_med, flag) == 1)
	{
		if (med >= main_med)
			if (ab->a_num <= 3 && srtd.flag == 1)
				mini_sort(ab, srtd, 0, 0);
			else if (srtd.flag == 0)
				mini_sort(ab, srtd, 1, 1);
			else
				mini_sort(ab, srtd, 0, 1);
		else
			if (ab->b_num <= 3 && srtd.flag == 0)
				mini_sort(ab, srtd, 1, 0);
			else if (srtd.flag == 0)
				mini_sort(ab, srtd, 1, 1);
			else if (srtd.flag == 1)
				mini_sort(ab, srtd, 0, 1);
		return (0);
	}
	if (med >= main_med)
	{
        if (srtd.flag == 1)
        	CHECK_ONE(push_b_main_even(ab, srtd, med, *flag))
        else
			if ((srtd.bot - srtd.top) % 2 == 0)
				push_a_main_even(ab, srtd, med);
			else
				push_a_main_uneven(ab, srtd, med);
    }
	else
	{
		if (srtd.flag == 1)
			push_b_secondary_even(ab, srtd, med);
		else
			if ((srtd.bot - srtd.top) % 2 == 0)
				push_a_secondary_even(ab, srtd, med);
			else
				push_a_secondary_uneven(ab, srtd, med);
	}
//	print_stack(*ab);
	q_sort_stack(ab, init_sorted(srtd, med, main_med, 1), main_med, flag);
	med == main_med ? *flag = 0 : 0;
	q_sort_stack(ab, init_sorted(srtd, med, main_med, 0), main_med, flag);
	return (0);
}

int	sort_stack(t_stacks *ab, int *sorted)
{
	t_sorted srtd;
	t_sorted lol;
	int med;
	int main_med;
	int flag;

	flag = 2;
	srtd.sorted = sorted;
	srtd.top = 0;
	srtd.bot = ab->num;
	srtd.flag = 1;
	q_sort_stack(ab, srtd, 0, &flag);
    return (0);
}
