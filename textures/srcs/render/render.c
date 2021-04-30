/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:45 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:20:50 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include "render.h"
#include "struct.h"
#include "utils.h"
#include "sprite.h"

int	render(t_cub3d *data)
{
	int		x;

	x = 0;
	data->ray.angle = round_rad(data->angle + (data->fov / 2));
	while (x < (int)data->def.x)
	{
		find_intersection(&data->ray, data);
		print_column(&data->ray, data, x);
		data->angle_buf[x] = round_rad(data->ray.angle);
		data->ray.angle = round_rad(data->ray.angle - data->step_rad);
		x++;
	}
	print_sprite(data);
	free_sprite(data->sprite);
	data->sprite = NULL;
	mlx_put_image_to_window(data->mlx.p, data->mlx.w, data->mlx.fra.img, 0, 0);
	return (0);
}

void	render_no_window(t_cub3d *data)
{
	int		x;

	x = 0;
	data->ray.angle = round_rad(data->angle + (data->fov / 2));
	while (x < (int)data->def.x)
	{
		find_intersection(&data->ray, data);
		print_column(&data->ray, data, x);
		data->angle_buf[x] = round_rad(data->ray.angle);
		data->ray.angle = round_rad(data->ray.angle - data->step_rad);
		x++;
	}
	print_sprite(data);
	free_sprite(data->sprite);
	data->sprite = NULL;
}
