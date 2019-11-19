/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:42:03 by gleonett          #+#    #+#             */
/*   Updated: 2018/11/28 11:39:55 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = -1;
	j = ft_strlen(src);
	while (++i < len)
		if (j > i)
			dst[i] = src[i];
		else
			(dst[i] = '\0');
	return (dst);
}
