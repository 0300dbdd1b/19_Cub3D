/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:36:46 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/04 17:57:46 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*result;
	size_t	i;

	chr = (char)c;
	result = (0);
	i = 0;
	if (chr == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == chr)
			result = (char *)s + i;
		i++;
	}
	return (result);
}
