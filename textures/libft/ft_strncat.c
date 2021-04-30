/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:25:46 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/20 21:30:57 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (src[i] && i < n)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = 0;
	return (dst);
}
