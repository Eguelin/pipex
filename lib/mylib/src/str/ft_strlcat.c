/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:00:43 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:24:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	pos_src;
	size_t	len_src;

	len_src = ft_strlen(src);
	pos = 0;
	pos_src = 0;
	if (!dstsize)
		return (len_src);
	while (dst[pos] && pos <= dstsize - 1)
		pos++;
	while (src[pos_src] && pos < dstsize - 1)
	{
		dst[pos] = src[pos_src];
		pos++;
		pos_src++;
	}
	if (pos_src)
		dst[pos] = 0;
	if (dstsize < pos - pos_src)
		return (dstsize + len_src);
	else
		return (pos - pos_src + len_src);
}
