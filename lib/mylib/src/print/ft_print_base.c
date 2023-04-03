/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:20:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_base(unsigned long un, unsigned long size_set, char *set)
{
	int	count;

	count = 0;
	if (un > size_set - 1)
		count += ft_print_base(un / size_set, size_set, set);
	count += ft_print_char(set[un % size_set]);
	return (count);
}
