/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:22:29 by gleonett          #+#    #+#             */
/*   Updated: 2018/11/30 14:39:06 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *obl;

	obl = malloc(size);
	if (obl == 0)
		return (0);
	ft_bzero(obl, size);
	return (obl);
}
