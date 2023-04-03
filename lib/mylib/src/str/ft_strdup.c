/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:50:43 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:24:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s1) + 1;
	s2 = malloc(size);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, size);
	return (s2);
}
