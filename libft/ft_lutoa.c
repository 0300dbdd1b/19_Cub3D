/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:51 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/02/13 22:15:40 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	number_size(unsigned long int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_lutoa(unsigned long int n)
{
	char	*res;
	size_t	i;

	i = number_size(n);
	res = malloc(sizeof(*res) * (i + 1));
	if (!res)
		return (0);
	res[i] = 0;
	i--;
	if (n == 0)
		res[i] = '0';
	while (n != 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res);
}
