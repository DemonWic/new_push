/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:36:45 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/20 17:36:48 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_elem(t_stacks *ab, int elem, int aorb, int j)
{
	int i;

	i = 0;
	if (aorb == 0)
	{
		while (i < j)
		{
			if (ab->b[ab->b_top] == elem)
			{
				many_rrb(ab, i, 1);
				return (0);
			}
			do_rb(ab, 1);
			++i;
		}
		many_rrb(ab, i, 1);
	}
	else
	{
		while (j > -1)
		{
			if (ab->b[ab->b_top] == elem)
				return (0);
			do_ra(ab, 1);
			j--;
		}
	}
	return (1);
}

int check_stack(t_stacks *ab, int med, int i)
{
	int	buf;
	int f;
	int k;

	f = 0;
	k = 0;
	while (ab->a[ab->a_top] > med)
	{
		--i;
		do_ra(ab, 1);
		k++;
		f++;
	}
	buf = ab->a[ab->a_top];
	while (--i > -1)
	{
		if (ab->a[ab->a_top] < buf)
		{
//			do_pb(ab, 1);
			do_ra(ab, 1);
			k++;
			f++;
		}
		else
		{
			buf = ab->a[ab->a_top];
			do_ra(ab, 1);
			k++;
		}
//		print_stack(*ab);
	}
	many_rra(ab, k, 1);
	return (f == 0 ? 1 : 0);
}

void sort_ten(t_stacks *ab, t_sorted srtd, int med, int aorb)
{
	const int	difference = srtd.bot - srtd.top;
	const int 	head = ab->a_top;
	int			i;
	int			buf;
	int 		nmb_rra;
	int f = 0;

	i = difference;
	nmb_rra = 0;
	if (check_stack(ab, med, i) == 1)
		return ;
	if (difference < 4)
	{
		mini_sort(ab, srtd, 0, 1);
		return ;
	}
//	ft_printf("%d\n", ab->a_top);
	while (ab->a[ab->a_top] > med)
	{
		--i;
		do_pb(ab, 0);
		f++;
	}
	buf = ab->a[ab->a_top];
	while (--i > -1)
	{
//		if (check_stack(ab, med, i) == 1)
//			break ;
		if (ab->a[ab->a_top] < buf)
		{
			do_pb(ab, 0);
			f++;
		}
		else
		{
			buf = ab->a[ab->a_top];
			do_ra(ab, 0);
			nmb_rra++;
		}
//		print_stack(*ab);
	}
//	if (difference - f < 4)
//	{
//		mini_sort(ab, srtd, 0, 1);
//		return ;
//	}
	int j = f;
	int k = 0;
	while (f > 0)
	{
//		ft_printf("%d %d %d %d %d %d %d %d %d %d\n", ab->a[0], ab->a[1],
//				ab->a[2], ab->a[3], ab->a[4], ab->a[5], ab->a[6], ab->a[7],
//				ab->a[8], ab->a[9]);
//		ft_printf("%d %d\n", ab->a[A_PREV], srtd.sorted[k]);
		if (ab->a[A_PREV] != srtd.sorted[k])
		{
			if (find_elem(ab, srtd.sorted[k], 0, j) == 0)
				while (ab->b[ab->b_top] != srtd.sorted[k])
				{
					do_rb(ab, 0);
					j--;
				}
			else
				while (ab->b[ab->b_top] != srtd.sorted[k])
				{
					j++;
					do_rrb(ab, 0);
				}
			do_pa(ab, 0);
			f--;
			j--;
			k++;
		}
		else
		{
			k++;
			do_rra(ab, 0);
			nmb_rra--;
		}
	}
	many_rra(ab, nmb_rra, 0);
}