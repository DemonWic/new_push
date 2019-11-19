/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:23:43 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 14:00:52 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int			checker(int num, const char **args)
{
	t_stacks	ab;
	char		*oper;
	int			ret;
	int			fail;
	int			num_num;

	if ((num_num = check_args(num, args)) == -1)
		return (1);
	CH_ERR_FREE(init_a_b_stacks(&ab, num, args, num_num) != 0);
	while ((fail = get_next_line(0, &oper)) > 0)
	{
		if (do_oper(&ab, oper) == 1)
		{
			ft_memdel((void **)&oper);
			ft_memdel((void **)(&(ab.a)));
			ft_memdel((void **)(&(ab.b)));
			return (1);
		}
		ft_memdel((void **)&oper);
	}
	ret = check_arr(ab, num);
	ft_memdel((void **)(&(ab.a)));
	ft_memdel((void **)(&(ab.b)));
	return (fail < 0 ? 1 : ret);
}
