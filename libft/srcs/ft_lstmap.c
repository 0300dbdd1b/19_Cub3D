/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:46:45 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 15:39:41 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mynewlist;
	t_list	*first;

	if (!lst)
		return (NULL);
	mynewlist = ft_lstnew(f(lst->content));
	if (!mynewlist)
		return (NULL);
	first = mynewlist;
	while (lst)
	{
		if (lst->next)
		{
			mynewlist->next = ft_lstnew(f(lst->next->content));
			if (!mynewlist->next)
			{
				ft_lstclear(&first, del);
				return (0);
			}
			mynewlist = mynewlist->next;
		}
		lst = lst->next;
	}
	mynewlist->next = NULL;
	return (first);
}
