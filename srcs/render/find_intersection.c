/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:33 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:12:36 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "render.h"

static int	find_h_intersect(t_ray *ray, t_cub3d *data)
{
	if (ray->up != 0)
	{
		if (ray->up == 1)
		{
			ray->i.y = floor(data->pos.y);
			ray->step_y = -1;
		}
		else
		{
			ray->i.y = floor(data->pos.y) + 1;
			ray->step_y = 1;
		}
		if (ray->left != 0)
		{
			ray->i.x = data->pos.x + (data->pos.y - ray->i.y) / tan(ray->angle);
			ray->step_x = (1 / tan(ray->angle)) * ray->up;
		}
		else
		{
			ray->i.x = data->pos.x;
			ray->step_x = 0;
		}
		return (check_hit_loop(ray, data, &check_h_hit));
	}
	return (0);
}

static int	find_v_intersection(t_ray *ray, t_cub3d *data)
{
	if (ray->left != 0)
	{
		if (ray->left == 1)
		{
			ray->i.x = floor(data->pos.x);
			ray->step_x = -1;
		}
		else
		{
			ray->i.x = floor(data->pos.x) + 1;
			ray->step_x = 1;
		}
		ray->i.y = data->pos.y + (data->pos.x - ray->i.x) * tan(ray->angle);
		ray->step_y = tan(ray->angle) * ray->left;
		return (check_hit_loop(ray, data, &check_v_hit));
	}
	return (0);
}

static void	get_text_dir(t_ray *ray)
{
	if (ray->dir == 1)
	{
		if (ray->up == 1)
			ray->text_dir = 1;
		else
			ray->text_dir = 3;
	}
	else
	{
		if (ray->left == 1)
			ray->text_dir = 0;
		else
			ray->text_dir = 2;
	}
}

static void	find_nearest_intersection(t_ray *ray, t_cub3d *d)
{
	double	h;
	double	v;

	h = sqrt(pow(d->pos.x - ray->h_i.x, 2) + pow(d->pos.y - ray->h_i.y, 2));
	v = sqrt(pow(d->pos.x - ray->v_i.x, 2) + pow(d->pos.y - ray->v_i.y, 2));
	if (ray->h_i.x != -1)
	{
		if (ray->v_i.x == -1 || h < v)
		{
			ray->i.x = ray->h_i.x;
			ray->i.y = ray->h_i.y;
			ray->dir = 1;
		}
	}
	get_text_dir(ray);
}

void	find_intersection(t_ray *ray, t_cub3d *data)
{
	ray->up = 0;
	ray->left = 0;
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->up = 1;
	else if (ray->angle > M_PI)
		ray->up = -1;
	if (ray->angle > M_PI / 2 && ray->angle < 3 * M_PI / 2)
		ray->left = 1;
	else if (ray->angle < M_PI / 2 || ray->angle > 3 * M_PI / 2)
		ray->left = -1;
	init_point(&ray->h_i);
	init_point(&ray->v_i);
	ray->dir = 0;
	if (find_h_intersect(ray, data))
	{
		ray->h_i.x = ray->i.x;
		ray->h_i.y = ray->i.y;
	}
	if (find_v_intersection(ray, data))
	{
		ray->v_i.x = ray->i.x;
		ray->v_i.y = ray->i.y;
	}
	find_nearest_intersection(ray, data);
}
