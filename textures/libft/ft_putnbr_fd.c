/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:07:00 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/04 17:55:47 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		sign *= -1;
	}
	if (n >= 10 || n <= -10)
		ft_putnbr_fd((n / 10) * sign, fd);
	res = (char)(((n % 10) * sign) + 48);
	write(fd, &res, 1);
}
