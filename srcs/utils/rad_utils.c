/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:36 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:15:17 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	deg2rad(double deg)
{
	return (deg * M_PI / 180);
}

double	rad2deg(double rad)
{
	return (rad * 180 / M_PI);
}

double	round_rad(double rad)
{
	while (rad >= 2 * M_PI)
		rad -= 2 * M_PI;
	while (rad < 0)
		rad += 2 * M_PI;
	return (rad);
}

int	is_greater_angle(double base, double cmp)
{
	double	left;
	double	right;

	left = round_rad(cmp - base);
	right = round_rad(base - cmp);
	if (left > right)
		return (1);
	return (0);
}
