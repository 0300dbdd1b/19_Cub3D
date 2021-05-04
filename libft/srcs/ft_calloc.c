/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:34:22 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 15:31:46 by naddino          ###   ########.fr       */
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
