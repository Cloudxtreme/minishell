/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:05:29 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 15:23:36 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ary_get(t_array *ary, size_t idx)
{
	char	*p;

	p = ((char*)ary->ptr) + (idx * ary->item_size);
	return ((void*)p);
}
