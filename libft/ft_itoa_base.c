/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:36 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/02/10 18:36:26 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_size(int n, size_t base)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(int n, const char *base)
{
	char	*res;
	int		sign;
	size_t	base_len;
	size_t	i;

	base_len = ft_strlen(base);
	i = number_size(n, base_len) - 1;
	sign = 1;
	res = ft_calloc(i + 2, sizeof(*res));
	if (!res)
		return (0);
	if (n < 0)
	{
		sign *= -1;
		res[0] = '-';
	}
	if (n == 0)
		res[i] = '0';
	while (n != 0)
	{
		res[i] = base[(n % base_len)] * sign;
		n /= base_len;
		i--;
	}
	return (res);
}
