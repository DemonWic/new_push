/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:38:51 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 16:07:55 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arr(t_stacks ab, int num)
{
	int i;
	int buf;

	i = 0;
	buf = ab.a[ab.a_top];
	while (++i < num)
	{
		do_ra(&ab, 1);
		if (ab.a[ab.a_top] < buf)
			return (2);
		buf = ab.a[ab.a_top];
	}
	return (0);
}

static void	init_debug(void)
{
	do_pa(NULL, 2);
	do_pb(NULL, 2);
	do_sa(NULL, 2);
	do_sb(NULL, 2);
	do_ss(NULL, 2);
	do_ra(NULL, 2);
	do_rb(NULL, 2);
	do_rr(NULL, 2);
	do_rra(NULL, 2);
	do_rrb(NULL, 2);
	do_rrr(NULL, 2);
}

int			sort_stack(t_stacks *ab, int *sorted)
{
	static int	ins_sort;
	t_sorted	srtd;
	int			flag;

	if (ab == NULL && sorted == NULL)
	{
		ins_sort++;
		return (0);
	}
	flag = 2;
	srtd.sorted = sorted;
	srtd.top = 0;
	srtd.bot = ab->num;
	srtd.flag = 1;
	if (ab->num < 4)
		mini_sort(ab, srtd, 0, 0);
	else if (ins_sort == 1)
		sort_a(ab, srtd);
	else
		q_sort_stack(ab, srtd, 0, &flag);
	return (0);
}

int			push_swap(int num, const char **args, int debug)
{
	t_stacks	ab;
	int			*sorted;
	int			ret;
	int			num_num;

	debug == 1 ? init_debug() : 0;
	debug == 3 ? sort_stack(NULL, NULL) : 0;
	if (debug == 2)
	{
		sort_stack(NULL, NULL);
		init_debug();
	}
	if ((num_num = check_args(num, args)) == -1)
		return (1);
	CH_ERR_FREE(init_a_b_stacks(&ab, num, args, num_num) != 0);
	CH_SORTED(sorted = pre_sort(ab));
	sort_stack(&ab, sorted);
	ret = check_arr(ab, num_num);
	ft_memdel((void **)(&(ab.a)));
	ft_memdel((void **)(&(ab.b)));
	ft_memdel((void **)&sorted);
	return (ret);
}
