/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:08:19 by gleonett          #+#    #+#             */
/*   Updated: 2018/12/01 08:55:40 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst > src)
		while (--len + 1 != 0)
			((char *)dst)[len] = ((char *)src)[len];
	else if (src == dst)
		return (dst);
	else
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
