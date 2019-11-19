/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:57:02 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 13:13:34 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f_checker/checker.h"

int		do_ra(t_stacks *ab, int flag)
{
	int			a_bot;
	static int	debug;

	if (flag == 2)
	{
		debug = 1;
		return (0);
	}
	if (flag == 0)
		ft_putstr_full("ra\n");
	if (ab->a_num < 2)
		return (0);
	if (ab->a_top + ab->a_num >= ab->num)
		a_bot = ab->a_top + ab->a_num - ab->num;
	else
		a_bot = ab->a_top + ab->a_num;
	ab->a[a_bot] = ab->a[ab->a_top];
	if ((ab->a_top += 1) == ab->num)
		ab->a_top = 0;
	debug == 1 && flag == 0 ? print_stack(ab, 3) : 0;
	return (0);
}

void	many_ra(t_stacks *ab, int num, int flag)
{
	while (--num > -1)
		do_ra(ab, flag);
}

int		do_rb(t_stacks *ab, int flag)
{
	int			b_bot;
	static int	debug;

	if (flag == 2)
	{
		debug = 1;
		return (0);
	}
	if (flag == 0)
		ft_putstr_full("rb\n");
	if (ab->b_num < 2)
		return (0);
	if (ab->b_top + ab->b_num >= ab->num)
		b_bot = ab->b_top + ab->b_num - ab->num;
	else
		b_bot = ab->b_top + ab->b_num;
	ab->b[b_bot] = ab->b[ab->b_top];
	if ((ab->b_top += 1) == ab->num)
		ab->b_top = 0;
	debug == 1 && flag == 0 ? print_stack(ab, 10) : 0;
	return (0);
}

void	many_rb(t_stacks *ab, int num, int flag)
{
	while (--num > -1)
		do_rb(ab, flag);
}

int		do_rr(t_stacks *ab, int flag)
{
	static int debug;

	if (flag == 2)
	{
		debug = 1;
		return (0);
	}
	if (flag == 0)
		ft_putstr_full("rr\n");
	do_ra(ab, 1);
	do_rb(ab, 1);
	debug == 1 && flag == 0 ? print_stack(ab, 6) : 0;
	return (0);
}
