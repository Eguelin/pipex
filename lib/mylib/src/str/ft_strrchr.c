/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:19:03 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:24:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	pos;

	pos = ft_strlen(s);
	while (pos > 0)
	{
		if (s[pos] == (char)c)
			return ((char *)(s + pos));
		pos--;
	}
	if (s[pos] == (char)c)
		return ((char *)(s + pos));
	return (NULL);
}
