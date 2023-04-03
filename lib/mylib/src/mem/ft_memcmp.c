/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:38:33 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:22:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (((unsigned char *)s1)[pos] != ((unsigned char *)s2)[pos])
			return (((unsigned char *)s1)[pos] - ((unsigned char *)s2)[pos]);
		pos++;
	}
	return (0);
}
