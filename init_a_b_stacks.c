/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_b_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:51:20 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 13:48:13 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_checker/checker.h"

static int	check_repetitions(int *a, int num)
{
	int i;
	int j;

	i = -1;
	while (++i < num)
	{
		j = i;
		while (++j < num)
			if (a[i] == a[j])
				return (1);
	}
	return (0);
}

static int	transfer(t_stacks *ab, const char *data, int *j)
{
	long int	buf;
	int			i;

	i = 0;
	while (data[i])
	{
		if (skip_spaces(data, &i))
			return (0);
		if ((buf = ft_atoli(data + i)) < -2147483648 || buf > 2147483647)
			return (1);
		ab->a[*j] = (int)buf;
		*j += 1;
		while (data[i] == '-' || data[i] == '+' || (data[i] >= '0' &&
				data[i] <= '9'))
			i++;
	}
	return (0);
}

int			init_a_b_stacks(t_stacks *ab, int num, const char **data,
		int num_num)
{
	int	i;
	int	j;

	CH_NULL(ab->a = (int *)ft_memalloc(sizeof(int) * num_num));
	CH_NULL(ab->b = (int *)ft_memalloc(sizeof(int) * num_num));
	i = -1;
	j = 0;
	while (++i < num)
		CHECK_ONE(transfer(ab, data[i], &j));
	CHECK_ONE(check_repetitions(ab->a, num_num));
	ab->num = num_num;
	ab->a_top = 0;
	ab->b_top = num_num;
	ab->a_num = num_num;
	ab->b_num = 0;
	return (0);
}
