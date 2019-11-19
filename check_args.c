/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:09:04 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/11 16:43:39 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_checker/checker.h"

int			skip_spaces(const char *arg, int *i)
{
	while (arg[*i] && (arg[*i] == '\t' || arg[*i] == ' '))
		*i += 1;
	return (arg[*i] == '\0' ? 1 : 0);
}

static int	check_arg(const char *arg)
{
	int i;
	int j;
	int num;

	i = 0;
	num = 0;
	while (arg[i] && (arg[i] == ' ' || arg[i] == '\t' || arg[i] == '\n' ||
			arg[i] == '-' || arg[i] == '+' || (arg[i] >= '0' && arg[i] <= '9')))
	{
		if (skip_spaces(arg, &i) == 1)
			return (num == 0 ? -1 : num);
		j = i;
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		while (arg[i] && arg[i] >= '0' && arg[i] <= '9')
			i++;
		if (i - j > 6)
			print_stack(NULL, -1);
		else if (i - j > 12 || ((arg[j] == '+' || arg[j] == '-') &&
		(i - j == 1)))
			return (-1);
		num++;
	}
	return (arg[i] != '\0' || num == 0 ? -1 : num);
}

int			check_args(int num, const char **data)
{
	int i;
	int res;
	int ret;

	i = -1;
	ret = 0;
	while (++i < num)
		if (data[i][0] == '\0' || (res = check_arg(data[i])) == -1)
			return (-1);
		else
			ret += res;
	return (ret);
}
