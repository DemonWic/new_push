/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:24:14 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/16 13:42:30 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bonuses(char **argv, int argc, int *i, int *flag)
{
	if (argc > 1 && ft_strcmp(argv[1], "--vc") == 0)
	{
		*i += 1;
		*flag = 1;
		if (argc > 2 && ft_strcmp(argv[2], "-i") == 0)
		{
			*i += 1;
			*flag = 2;
		}
	}
	if (argc > 1 && ft_strcmp(argv[1], "-i") == 0)
	{
		*i += 1;
		*flag = 3;
		if (argc > 2 && ft_strcmp(argv[2], "--vc") == 0)
		{
			*i += 1;
			*flag = 2;
		}
	}
}

int			main(int argc, char **argv)
{
	int res;
	int i;
	int flag;

	if (argc < 2)
		return (1);
	flag = 0;
	i = 0;
	bonuses(argv, argc, &i, &flag);
	if (argv[i + 1] == NULL || argv[i + 1][0] == '\0')
	{
		ft_printf("%{PURPLE Error\n");
		return (1);
	}
	if ((res = push_swap(argc - 1 - i, (const char **)argv + 1 + i, flag)) == 1)
		ft_printf("%{PURPLE Error\n");
	return (0);
}
