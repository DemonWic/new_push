/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:11:08 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 12:54:32 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f_checker/checker.h"

int		do_pa(t_stacks *ab, int flag)
{
	static int debug;

	if (flag == 2)
	{
		debug = 1;
		return (0);
	}
	if (flag == 0)
		ft_putstr_full("pa\n");
	if (ab->b_num < 1)
		return (0);
	if ((ab->a_top -= 1) < 0)
		ab->a_top = ab->num - 1;
	ab->a[ab->a_top] = ab->b[ab->b_top];
	if ((ab->b_top += 1) >= ab->num)
		ab->b_top = 0;
	ab->a_num += 1;
	ab->b_num -= 1;
	debug == 1 && flag == 0 ? print_stack(ab, 1) : 0;
	return (0);
}

int		do_pb(t_stacks *ab, int flag)
{
	static int debug;

	if (flag == 2)
	{
		debug = 1;
		return (0);
	}
	if (flag == 0)
		ft_putstr_full("pb\n");
	if (ab->a_num < 1)
		return (0);
	if ((ab->b_top -= 1) < 0)
		ab->b_top = ab->num - 1;
	ab->b[ab->b_top] = ab->a[ab->a_top];
	if ((ab->a_top += 1) >= ab->num)
		ab->a_top = 0;
	ab->a_num -= 1;
	ab->b_num += 1;
	debug == 1 && flag == 0 ? print_stack(ab, 8) : 0;
	return (0);
}

void	many_pa(t_stacks *ab, int num, int flag)
{
	while (--num > -1)
		do_pa(ab, flag);
}
