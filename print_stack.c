/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:29:26 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/14 15:29:26 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_checker/checker.h"

static void	print_changes_ab_top(int nmbr, int flag, int aorb, int big)
{
	if (aorb == 0)
	{
		if (flag == 1 || flag == 2 || flag == 5 || flag == 4 || flag == 7)
			ft_printf(PURPLE"%*d", big == 12 ? big : 7, nmbr);
		else
			ft_printf(RED"%*d", big == 12 ? big : 7, nmbr);
	}
	else
	{
		if (flag == 8 || flag == 9 || flag == 5 || flag == 11 || flag == 7)
			ft_printf(PURPLE"%*d\n", big == 12 ? big + 1 : 7, nmbr);
		else
			ft_printf(YELLOW"%*d\n", big == 12 ? big + 1 : 7, nmbr);
	}
}

static void	print_changes_ab(t_stacks *ab, int i, int flag, int aorb)
{
	static int big;

	if (ab == NULL)
	{
		big = 12;
		return ;
	}
	if (aorb == 0)
	{
		if (i == A_PREV && (flag == 3 || flag == 6))
			ft_printf(PURPLE"%*d", big == 12 ? big : 7, ab->a[i]);
		else if (i == A_NEXT && (flag == 2 || flag == 5))
			ft_printf(PURPLE"%*d", big == 12 ? big : 7, ab->a[i]);
		else
			ft_printf(RED"%*d", big == 12 ? big : 7, ab->a[i]);
	}
	else
	{
		if (i == B_PREV && (flag == 10 || flag == 6))
			ft_printf(PURPLE"%*d\n", big == 12 ? big + 1 : 7, ab->b[i]);
		else if (i == B_NEXT && (flag == 9 || flag == 5))
			ft_printf(PURPLE"%*d\n", big == 12 ? big + 1 : 7, ab->b[i]);
		else
			ft_printf(YELLOW"%*d\n", big == 12 ? big + 1 : 7, ab->b[i]);
	}
}

void		print_stack(t_stacks *ab, int flag)
{
	static int	big;
	int			i;
	int			j;
	int			x;

	INIT_BIG_WIDE(flag);
	I_J_X_INIT(i, j, x);
	while (++x < ab->num)
	{
		if (i == ab->a_top && i > -1 && ab->a_num > 0)
			print_changes_ab_top(ab->a[i], flag, 0, big);
		else if (x >= ab->a_num)
			ft_printf(RED"%*c", big == 12 ? big : 7, '_');
		else
			print_changes_ab(ab, i, flag, 0);
		if (ab->b_top == j && j > -1 && ab->b_num > 0)
			print_changes_ab_top(ab->b[j], flag, 1, big);
		else if (x >= ab->b_num)
			ft_printf(YELLOW"%*c\n"REBOOT, big == 12 ? big + 1 : 7, '_');
		else
			print_changes_ab(ab, j, flag, 1);
		i == ab->num - 1 && x < ab->a_num ? i = 0 : i++;
		j == ab->num - 1 && x < ab->b_num ? j = 0 : j++;
	}
	ft_putchar('\n');
}
