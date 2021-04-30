/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:50:38 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/04 17:52:32 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	size_t	i;

	i = number_size(n);
	sign = 1;
	res = malloc(sizeof(*res) * (i + 1));
	if (!res)
		return (0);
	res[i] = 0;
	i--;
	if (n < 0)
	{
		sign *= -1;
		res[0] = '-';
	}
	if (n == 0)
		res[i] = '0';
	while (n != 0)
	{
		res[i] = ((n % 10) * sign) + 48;
		n /= 10;
		i--;
	}
	return (res);
}
