/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:07:35 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/04 17:57:29 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i_s1;
	size_t	i_s2;

	if (!s2[0])
		return ((char *)s1);
	i_s1 = 0;
	while (s1[i_s1] && i_s1 < len)
	{
		i_s2 = 0;
		while (s1[i_s1 + i_s2] == s2[i_s2] && i_s1 + i_s2 < len && s2[i_s2])
			i_s2++;
		if (!s2[i_s2])
			return ((char *)s1 + i_s1);
		i_s1++;
	}
	return (0);
}
