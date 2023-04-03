/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:33:06 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:24:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	pos;
	char	*s2;

	if (!s || !f)
		return (NULL);
	pos = 0;
	s2 = malloc(ft_strlen(s) + 1);
	if (!s2)
		return (NULL);
	while (s[pos])
	{
		s2[pos] = (*f)(pos, s[pos]);
		pos++;
	}
	s2[pos] = 0;
	return (s2);
}
