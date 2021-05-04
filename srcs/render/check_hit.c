/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:28 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:12:31 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "sprite.h"

int	check_h_hit(t_cub3d *d, t_ray *ray, t_map *map)
{
	double	up;

	up = 0;
	if (ray->up == 1)
		up = 1;
	if (ray->i.x >= 0 && ray->i.y >= 0
		&& ray->i.x < map->w && ray->i.y < map->h)
	{
		if (map->map[(int)(ray->i.y - up)][(int)ray->i.x] == 1)
			return (1);
		else if (map->map[(int)(ray->i.y - up)][(int)ray->i.x] == 2)
			sprite_found(d, floor(ray->i.x) + 0.5, floor(ray->i.y - up) + 0.5);
		return (0);
	}
	return (-1);
}

int	check_v_hit(t_cub3d *d, t_ray *ray, t_map *map)
{
	double	l;

	l = 0;
	if (ray->left == 1)
		l = 1;
	if (ray->i.x >= 0 && ray->i.y >= 0
		&& ray->i.x < map->w && ray->i.y < map->h)
	{
		if (map->map[(int)ray->i.y][(int)(ray->i.x - l)] == 1)
			return (1);
		else if (map->map[(int)ray->i.y][(int)(ray->i.x - l)] == 2)
			sprite_found(d, floor(ray->i.x - l) + 0.5, floor(ray->i.y) + 0.5);
		return (0);
	}
	return (-1);
}

int	check_hit_loop(t_ray *ray, t_cub3d *data,
				int (*f)(t_cub3d *data, t_ray *ray, t_map *map))
{
	int	hit;

	hit = (*f)(data, ray, &data->map);
	while (!hit)
	{
		ray->i.x += ray->step_x;
		ray->i.y += ray->step_y;
		hit = (*f)(data, ray, &data->map);
	}
	if (hit == -1)
		return (0);
	return (1);
}
