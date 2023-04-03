/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:24:43 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	pos;
	size_t	len_s;

	if (!s)
		return (NULL);
	pos = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		s2 = malloc(1);
	else if (len_s - start < len)
		s2 = malloc(len_s - start + 1);
	else
		s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	while (pos < len && pos < len_s - start && !(start >= len_s))
	{
		s2[pos] = (s + start)[pos];
		pos++;
	}
	s2[pos] = 0;
	return (s2);
}
