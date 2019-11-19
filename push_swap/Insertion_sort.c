/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:15:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/22 15:15:07 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_stacks *ab, t_sorted sorted)
{
	const int start = A_PREV;
	int i;
	int j;

	i = sorted.bot - 1;
	j = 0;
	print_stack(*ab);
	while (i >= sorted.top)
	{
		while (ab->a[ab->a_top] > ab->a[A_NEXT])
		{
			//			ft_printf("[%d] [%d]\n", ab->a[ab->a_top], ab->a[A_NEXT]);
			//			print_stack(*ab);
			do_sa(ab, 0);
			if (ab->a[ab->a_top] < ab->a[A_PREV] && A_PREV != start)
			{
				do_rra(ab, 0);
				j--;
				i++;
			}
			//			print_stack(*ab);
		}
		//		ft_printf("[%d] [%d]\n", ab->a[ab->a_top], ab->a[A_NEXT]);
//				print_stack(*ab);
		if (check_stack_a(ab, sorted, i) == 0)
			break ;
		do_ra(ab, 0);
		j++;
//				print_stack(*ab);
		i--;
	}
	many_rra(ab, j, 0);
//	print_stack(*ab);
}

static void	sort_b(t_stacks *ab, t_sorted sorted)
{
	int i;

	i = sorted.top - 1;
	while (++i < sorted.bot)
	{
		if (find_elem_isort(ab, sorted, i) == 0)
			while (ab->b[ab->b_top] != sorted.sorted[i])
				do_rb(ab, 0);
		else
			while (ab->b[ab->b_top] != sorted.sorted[i])
				do_rrb(ab, 0);
		do_pa(ab, 0);
	}
}

void find_const(int *f, int num)
{
	if (num == 4)
		*f = 6;
	else if (num == 5)
		*f = 8;
	else if (num == 6)
		*f = 10;
	else if (num == 7)
		*f = 12;
	else if (num == 8)
		*f = 15;
	else if (num == 9)
		*f = 17;
	else if (num == 10)
		*f = 25;
	else if (num > 9 && num < 20)
		*f = 84;
	else if (num > 19 && num < 30)
		*f = 150;
	else if (num > 29 && num < 40)
		*f = 220;
	else if (num > 39 && num < 50)
		*f = 300;
	else if (num > 49 && num < 60)
		*f = 400;
	else if (num > 59 && num < 70)
		*f = 460;
	else if (num > 69 && num < 80)
		*f = 550;
	else if (num > 79 && num < 90)
		*f = 650;
	else if (num > 89 && num < 100)
		*f = 750;
	else if (num > 99 && num < 200)
		*f = 1780;
	else if (num > 199 && num < 300)
		*f = 3000;
	else if (num > 299 && num < 400)
		*f = 4150;
	else if (num > 399 && num < 500)
		*f = 5500;
	else if (num > 499 && num < 600)
		*f = 6700;
	else if (num > 599 && num < 700)
		*f = 8100;
	else if (num > 699 && num < 800)
		*f = 9500;
	else if (num > 799 && num < 900)
		*f = 11000;
	else if (num > 899 && num < 1000)
		*f = 12400;
}

int	insertion_sort(t_stacks *ab, t_sorted sorted, int aorb)
{
	t_stacks *cpy;
	int f;

	if (sorted.bot - sorted.top < 4)
		return (0);
	find_const(&f, sorted.bot - sorted.top);
	if (sorted.bot - sorted.top > 10)
		f = (int)((sorted.bot - sorted.top - 34.4947) / 0.08034);
	cpy = cpy_stacks(*ab);
	if (aorb == 1)
	{
		if (pre_insort_a(cpy, sorted, f) == 1)
		{
			del_stacks(&cpy);
			return (0);
		}
		else
			sort_a(ab, sorted);
	}
	else
	{
		if (pre_insort_b(cpy, sorted, f) == 1)
		{
			del_stacks(&cpy);
			return (0);
		}
		else
			sort_b(ab, sorted);
	}
//	print_stack(*ab);
	del_stacks(&cpy);
	return (1);
}