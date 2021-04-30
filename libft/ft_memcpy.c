/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:04:22 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/04 17:54:29 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = dst;
	source = src;
	if (dest == 0 && source == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
