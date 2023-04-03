/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:20:55 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_nbr(int n)
{
	unsigned int	un;
	int				count;

	un = n;
	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		un *= -1;
	}
	if (un > 9)
		count += ft_print_nbr(un / 10);
	count += ft_print_char((un % 10) + '0');
	return (count);
}
