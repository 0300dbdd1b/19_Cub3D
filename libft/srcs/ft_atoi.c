/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:07:12 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 15:18:34 by naddino          ###   ########.fr       */
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
