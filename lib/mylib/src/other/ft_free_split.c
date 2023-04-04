/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:02:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/04 14:51:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}
