/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:24:07 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:21:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_printf(const char *format, ...)
{
	va_list	larg;
	size_t	pos;
	int		size;

	pos = 0;
	size = 0;
	if (write(1, 0, 0) != 0 || !format)
		return (-1);
	va_start(larg, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			size += ft_print_all(format[pos + 1], larg);
		}
		else
			size += ft_print_char(format[pos]);
		if (format[pos + 1] && format[pos] == '%')
			pos ++;
		pos++;
	}
	va_end(larg);
	return (size);
}
