/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:58:09 by gleonett          #+#    #+#             */
/*   Updated: 2018/11/30 14:46:56 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		a;

	if (!s)
		return (0);
	if (!f)
		return (0);
	a = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * a + 1);
	if (!new)
		return (0);
	while (*s)
		*new++ = f(*s++);
	*new = '\0';
	return (new - a);
}
