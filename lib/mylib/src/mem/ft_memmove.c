/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:26:15 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:22:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	pos;

	pos = 0;
	if (dst > src)
	{
		while (pos < len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
