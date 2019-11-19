/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_or_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:57:42 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/20 11:57:44 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ra(t_stacks *stack_r, int med, int difference)
{
	int i;
	int cnt_r;

	i = 0;
	cnt_r = 0;
	while (i < difference)
	{
		if (stack_r->a[stack_r->a_top] <= med)
		{
			i++;
			do_pb(stack_r, 1);
		}
		else
		{
			cnt_r++;
			do_ra(stack_r, 1);
		}
	}
	return (cnt_r);
}

int	count_rra(t_stacks *stack_rr, int med, int difference)
{
	int i;
	int cnt_rr;

	i = 0;
	cnt_rr = 0;
	while (i < difference)
	{
		if (stack_rr->a[stack_rr->a_top] <= med)
		{
			i++;
			do_pb(stack_rr, 1);
		}
		else
		{
			cnt_rr++;
			do_rra(stack_rr, 1);
		}
	}
	return (cnt_rr);
}

int	count_rb(t_stacks *stack_r, int med, int difference)
{
	int i;
	int cnt_r;

	i = 0;
	cnt_r = 0;
	while (i < difference)
	{
		if (stack_r->b[stack_r->b_top] > med)
		{
			i++;
			do_pa(stack_r, 1);
		}
		else
		{
			cnt_r++;
			do_rb(stack_r, 1);
		}
	}
	return (cnt_r);
}

int	count_rrb(t_stacks *stack_rr, int med, int difference)
{
	int i;
	int cnt_rr;

	i = 0;
	cnt_rr = 0;
	while (i < difference)
	{
		if (stack_rr->b[stack_rr->b_top] > med)
		{
			i++;
			do_pa(stack_rr, 1);
		}
		else
		{
			cnt_rr++;
			do_rrb(stack_rr, 1);
		}
	}
	return (cnt_rr);
}

int	r_or_rr(t_stacks ab, int aorb, int med, int difference)
{
	int			cnt_r;
	int			cnt_rr;
	t_stacks	*stack_r;
	t_stacks	*stack_rr;

	stack_r = cpy_stacks(ab);
	stack_rr = cpy_stacks(ab);
	if (aorb == 0)
	{
		cnt_r = count_ra(stack_r, med, difference);
		cnt_rr = count_rra(stack_rr, med, difference);
	}
	else
	{
		cnt_r = count_rb(stack_r, med, difference);
		cnt_rr = count_rrb(stack_rr, med, difference);
	}
	del_stacks(&stack_r);
	del_stacks(&stack_rr);
	return (cnt_r < cnt_rr ? 0 : 1);
}
