/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:38:13 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/20 14:38:16 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*cpy_stacks(t_stacks ab)
{
	t_stacks *ret;

	CH_NULL(ret = (t_stacks *)malloc(sizeof(t_stacks)));
	CH_NULL(ret->a = (int *)malloc(sizeof(int) * ab.num));
	CH_NULL(ret->b = (int *)malloc(sizeof(int) * ab.num));
	ft_memcpy(ret->a, ab.a, sizeof(int) * ab.num);
	ft_memcpy(ret->b, ab.b, sizeof(int) * ab.num);
	ret->a_top = ab.a_top;
	ret->b_top = ab.b_top;
	ret->a_num = ab.a_num;
	ret->b_num = ab.b_num;
	ret->num = ab.num;
	return (ret);
}

void		del_stacks(t_stacks **ab)
{
	ft_memdel((void **)&((*ab)->a));
	ft_memdel((void **)&((*ab)->b));
	ft_memdel((void **)ab);
}
