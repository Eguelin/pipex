/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:02:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:23:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (count > 0 && size >= SIZE_MAX / count)
		return (NULL);
	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, count * size);
	return (alloc);
}
