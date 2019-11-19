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

void		find_const(int *f, int num)
{
	const int opers[] = {0, 0, 0, 0, 0, 4, 6, 8, 12, 14, 16, 18, 18, 20, 22, 24,
						28, 34, 36, 38, 40, 44, 46, 48, 48, 50, 52, 54, 56, 60};

	if (num < 31)
		*f = opers[num];
	else if (num < 101)
		*f = (int)((num - 14.4998) / 0.285);
	else if (num < 201)
		*f = (int)((num - 33.4741) / 0.2338);
	else if (num < 501)
		*f = (int)((num - 42.4175) / 0.22676);
	else if (num < 1001)
		*f = (int)((num - 23.5676) / 0.2176);
	else
		*f = (int)((num - 1039.0165) / 0.13734);
}

static void	come_back(t_stacks *ab, int start, int *i, int *j)
{
	while (ab->a[ab->a_top] > ab->a[A_NEXT])
	{
		ab->b[ab->b_top] < ab->b[B_NEXT] ? do_ss(ab, 0) : do_sa(ab, 0);
		if (ab->a[ab->a_top] < ab->a[A_PREV] && A_PREV != start)
		{
			do_rrr(ab, 0);
			*j -= 1;
			*i += 1;
		}
	}
}

void		sort_a(t_stacks *ab, t_sorted sorted)
{
	const int	start = A_PREV;
	int			i;
	int			j;

	i = sorted.bot - 1;
	j = 0;
	while (i >= sorted.top)
	{
		come_back(ab, start, &i, &j);
		ab->b[ab->b_top] < ab->b[B_NEXT] && ab->b_num > 2 ? do_sb(ab, 0) : 0;
		if (check_stack_a(ab, sorted, i) == 0)
			break ;
		do_rr(ab, 0);
		j++;
		i--;
	}
	while (j < (NUM_INTERVAL / 2) || ab->b_num > 2 ?
			--j > -1 : ++j < sorted.bot + 1)
	{
		j < (NUM_INTERVAL / 2) || ab->b_num > 2 ?
				do_rrr(ab, 0) : do_rr(ab, 0);
		ab->b[ab->b_top] < ab->b[B_NEXT] && ab->b_num > 2 ? do_sb(ab, 0) : 0;
	}
}

static void	sort_b(t_stacks *ab, t_sorted sorted)
{
	int i;

	i = sorted.top - 1;
	while (++i < sorted.bot)
	{
		if (ab->b[ab->b_top] != sorted.sorted[i])
		{
			if (find_elem_isort(ab, sorted, i) == 0)
				while (ab->b[ab->b_top] != sorted.sorted[i])
					do_rb(ab, 0);
			else
				while (ab->b[ab->b_top] != sorted.sorted[i])
					do_rrb(ab, 0);
		}
		do_pa(ab, 0);
	}
}

int			insertion_sort(t_stacks *ab, t_sorted sorted)
{
	t_stacks	*cpy;
	int			f;

	if (NUM_INTERVAL > 4)
	{
		find_const(&f, sorted.bot - sorted.top);
		cpy = cpy_stacks(*ab);
	}
	if (sorted.flag == 1)
	{
		if (sorted.bot - sorted.top > 4 && pre_insort_a(cpy, sorted, f) == 1)
			DEL_STACKS_RETURN(&cpy);
		else
			sort_a(ab, sorted);
	}
	else
	{
		if (sorted.bot - sorted.top > 4 && pre_insort_b(cpy, sorted, f) == 1)
			DEL_STACKS_RETURN(&cpy);
		else
			sort_b(ab, sorted);
	}
	sorted.bot - sorted.top > 4 ? del_stacks(&cpy) : 0;
	return (1);
}
