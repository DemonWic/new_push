/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:18:55 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 13:58:06 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int res;
	int i;

	if (argc < 2)
		return (1);
	i = ft_strcmp(argv[1], "--vc") == 0 ? 1 : 0;
	if ((res = checker(argc - 1 - i, (const char **)argv + 1 + i)) == 1)
		ft_printf("%{PURPLE Error\n");
	else if (res == 2)
		ft_printf("%{RED KO\n");
	else if (res == 0)
		ft_printf("%{GREEN OK\n");
	return (0);
}
