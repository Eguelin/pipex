/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:18:32 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:22:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	pos;

	pos = 0;
	if (!dst && !src)
		return (dst);
	while (pos < n)
	{
		((unsigned char *)dst)[pos] = ((const unsigned char *)src)[pos];
		pos++;
	}
	return (dst);
}
