/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprite_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:27 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:13:01 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "utils.h"

static int	out_of_bound_sprite_col(t_sprite *s, t_cub3d *d, int dir)
{
	double	tmp_angle;
	int		col;

	col = 0;
	if (dir == -1)
	{
		tmp_angle = d->angle_buf[0];
		while (is_greater_angle(s->angle, tmp_angle))
		{
			tmp_angle = round_rad(tmp_angle + d->step_rad);
			col--;
		}
	}
	else if (dir == 1)
	{
		tmp_angle = d->angle_buf[(int)d->def.x - 1];
		col = d->def.x - 1;
		while (is_greater_angle(tmp_angle, s->angle))
		{
			tmp_angle = round_rad(tmp_angle - d->step_rad);
			col++;
		}
	}
	return (col);
}

double	find_sprite_col(t_sprite *s, t_cub3d *d)
{
	int	col;

	if (is_greater_angle(s->angle, d->angle_buf[0]))
		col = out_of_bound_sprite_col(s, d, -1);
	else if (is_greater_angle(d->angle_buf[(int)d->def.x - 1], s->angle))
		col = out_of_bound_sprite_col(s, d, 1);
	else
	{
		col = 0;
		while (is_greater_angle(d->angle_buf[col], s->angle))
			col++;
	}
	return (col);
}
