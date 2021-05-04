/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:51:57 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 15:52:07 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	long int	i;

	i = nbr;
	if (ft_check_base(base) != 0)
	{
		if (i < 0)
		{
			ft_putchar('-');
			i = i * (-1);
		}
		if (i >= (int)ft_strlen(base))
		{
			ft_putnbr_base(i / (int)ft_strlen(base), base);
			ft_putnbr_base(i % (int)ft_strlen(base), base);
		}
		else
			ft_putchar(base[i % (int)ft_strlen(base)]);
	}
}
