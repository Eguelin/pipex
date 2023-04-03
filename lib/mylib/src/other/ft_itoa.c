/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:44:07 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:23:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while ((unsigned int)n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*nstr;
	int		nsize;
	int		neg;

	neg = 0;
	nsize = ft_count(n);
	nstr = malloc(nsize + 1);
	if (!nstr)
		return (NULL);
	nstr[nsize] = 0;
	while (nsize > 0)
	{
		if (n < 0)
		{
			n *= -1;
			neg = 1;
		}
		nsize--;
		nstr[nsize] = ((unsigned int)n % 10) + 48;
		n = n / 10;
	}
	if (neg)
		nstr[0] = '-';
	return (nstr);
}
