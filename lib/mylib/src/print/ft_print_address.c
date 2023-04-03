/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:20:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_print_address(unsigned long un)
{
	ft_print_str("0x");
	return (2 + ft_print_base(un, 16, "0123456789abcdef"));
}
