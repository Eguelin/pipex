/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:38:13 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:24:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	pos;

	if (!s || !f)
		return ;
	pos = 0;
	while (s[pos])
	{
		(*f)(pos, s + pos);
		pos++;
	}
}
