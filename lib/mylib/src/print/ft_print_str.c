/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:22:47 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:20:58 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_str(const char *s)
{
	int	pos;

	pos = 0;
	while (s[pos])
	{
		ft_print_char(s[pos]);
		pos++;
	}
	return (pos);
}
