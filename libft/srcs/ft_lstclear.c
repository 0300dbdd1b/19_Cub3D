/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:30:27 by naddino           #+#    #+#             */
/*   Updated: 2020/01/20 18:46:22 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!del || !lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		(del)(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
