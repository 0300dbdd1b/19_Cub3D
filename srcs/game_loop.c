/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:58 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:16:02 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "render.h"
#include "key.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "game.h"

static void	get_step(t_cub3d *data, double *step_x, double *step_y)
{
	t_vect	wall;
	t_vect	unit;
	double	step;

	step = 0.5;
	wall.x = data->ray.i.x - data->pos.x;
	wall.y = data->ray.i.y - data->pos.y;
	wall.len = sqrt(pow(wall.x, 2) + pow(wall.y, 2));
	unit.x = wall.x / wall.len;
	unit.y = wall.y / wall.len;
	if (wall.len <= step)
		step = wall.len - 0.3;
	if (step < 0)
		step = 0;
	*step_x = unit.x * step;
	*step_y = unit.y * step;
}

static void	update_pos(int key, t_cub3d *data)
{
	double	step_x;
	double	step_y;

	if (key == DOWN)
		data->ray.angle = round_rad(data->angle + M_PI);
	else if (key == LEFT)
		data->ray.angle = round_rad(data->angle + (M_PI / 2));
	else if (key == RIGHT)
		data->ray.angle = round_rad(data->angle - (M_PI / 2));
	else
		data->ray.angle = data->angle;
	find_intersection(&data->ray, data);
	get_step(data, &step_x, &step_y);
	step_x += data->pos.x;
	step_y += data->pos.y;
	if (data->map.map[(int)step_y][(int)step_x] != 1)
	{
		data->pos.x = step_x;
		data->pos.y = step_y;
	}
}

static int	exit_hook(t_cub3d *data)
{
	free_data(data);
	exit(0);
}

static int	key_hook(int key, t_cub3d *data)
{
	if (key == ESC)
		exit_hook(data);
	if (key == LEFT_ARROW)
		data->angle = round_rad(data->angle + 0.1);
	else if (key == RIGHT_ARROW)
		data->angle = round_rad(data->angle - 0.1);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		update_pos(key, data);
	render(data);
	return (0);
}

void	game_loop(t_cub3d *data)
{
	mlx_setup(&data->mlx, data);
	data->step_rad = round_rad(data->fov / data->def.x);
	data->d_to_screen = (data->def.x / 2) / tan(data->fov / 2);
	if (data->save == 1)
	{
		data->save = 0;
		render_no_window(data);
		save_bmp(&data->mlx.fra, data);
		return ;
	}
	mlx_hook(data->mlx.w, 33, 1L << 17, &exit_hook, data);
	mlx_key_hook(data->mlx.w, &key_hook, data);
	mlx_loop_hook(data->mlx.p, &render, data);
	mlx_loop(data->mlx.p);
}
