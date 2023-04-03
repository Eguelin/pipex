/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:29:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/01 19:55:24 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(char **))
{
	t_list	*newlst;
	t_list	*new;
	void	*new_content;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			del(new_content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}
