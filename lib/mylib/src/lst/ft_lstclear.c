/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/01 19:55:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_lstclear(t_list **lst, void (*del)(char **))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
