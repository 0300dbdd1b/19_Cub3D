/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:19:57 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:19:59 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "struct.h"
#include "utils.h"

static double	set_angle(char dir)
{
	if (dir == 'N')
		return (deg2rad(90));
	else if (dir == 'S')
		return (deg2rad(270));
	else if (dir == 'E')
		return (deg2rad(0));
	else
		return (deg2rad(180));
}

static void	set_pos(t_point *pos, double x, double y)
{
	pos->x = x + 0.5;
	pos->y = y + 0.5;
}

int	get_pos(char **map, t_cub3d *data)
{
	size_t	x;
	size_t	y;
	int		find;

	y = 0;
	find = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				find++;
				set_pos(&data->pos, (double)x, (double)y);
				data->angle = set_angle(map[y][x]);
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (find);
}
