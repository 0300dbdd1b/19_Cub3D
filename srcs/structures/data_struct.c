/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:45 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:13:28 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "utils.h"

void	init_temp(t_temp *temp)
{
	temp->fd = -1;
	temp->line = NULL;
	temp->trim = NULL;
	temp->x = 0;
	temp->y = 0;
	temp->north = NULL;
	temp->south = NULL;
	temp->west = NULL;
	temp->east = NULL;
	temp->sprite = NULL;
	temp->f[0] = -1;
	temp->f[1] = -1;
	temp->f[2] = -1;
	temp->c[0] = -1;
	temp->c[1] = -1;
	temp->c[2] = -1;
	temp->map.h = 0;
	temp->map.w = 0;
	temp->map.map = NULL;
	temp->count = 0;
}

void	init_cub3d(t_cub3d *data)
{
	init_mlx(&data->mlx);
	init_point(&data->pos);
	init_point(&data->def);
	data->map.h = 0;
	data->map.w = 0;
	data->map.map = NULL;
	data->angle = 0;
	init_ray(&data->ray);
	data->fov = round_rad(deg2rad(60));
	data->step_rad = 0;
	init_text(&data->txt_sp);
	init_text(&data->text_n);
	init_text(&data->text_s);
	init_text(&data->text_e);
	init_text(&data->text_w);
	data->color_ceil = 0;
	data->color_floor = 0;
	data->z_buf = NULL;
	data->angle_buf = NULL;
	data->sprite = NULL;
	data->save = 0;
}
