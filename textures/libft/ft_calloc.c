/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:06:26 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/04 17:51:49 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			len;
	unsigned char	*result;

	len = nmemb * size;
	result = malloc(len);
	if (!result)
		return (0);
	while (len > 0)
	{
		result[len - 1] = 0;
		len--;
	}
	return ((void *)result);
}
