/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:02:45 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/11 19:25:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	size_t	size;

	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
	else
		size = ft_strlen(s2) + 1;
	join = malloc(size);
	if (!join)
		return (NULL);
	if (!s1)
	{
		ft_strlcpy(join, s2, size);
		free(s2);
		return (join);
	}
	ft_strlcpy(join, s1, size);
	free(s1);
	ft_strlcat(join, s2, size);
	free(s2);
	return (join);
}
