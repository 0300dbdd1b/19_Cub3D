/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:06:18 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/20 20:03:01 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	long int		result;
	size_t			i;

	i = 0;
	sign = -1;
	result = 0;
	while (ft_isspace((int)str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit((int)str[i]))
	{
		result = (result * 10) - (str[i++] - 48);
		if (result > 0)
		{
			if (sign > 0)
				return (0);
			else
				return (-1);
		}
	}
	return (result * sign);
}
