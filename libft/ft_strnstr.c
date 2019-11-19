/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:09:43 by gleonett          #+#    #+#             */
/*   Updated: 2018/12/02 13:28:15 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j] || needle[j] == '\0') && \
			i + j <= len)
		{
			if (needle[j] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
