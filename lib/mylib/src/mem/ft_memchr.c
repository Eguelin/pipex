/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:31:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:22:43 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (((unsigned char *)s)[pos] == (unsigned char)c)
			return ((void *)(s + pos));
		pos++;
	}
	return (NULL);
}
