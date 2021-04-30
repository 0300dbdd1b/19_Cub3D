/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:19:19 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:19:41 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"
#include "struct.h"
#include "error.h"

static int	check_valid_map_char(char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0'
			&& map[y][x] != '2' && map[y][x] != 'N'
			&& map[y][x] != 'S' && map[y][x] != 'E'
			&& map[y][x] != 'W' && map[y][x] != ' ')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_valid_line(char *line)
{
	size_t	x;
	int		in;

	x = -1;
	in = 0;
	if (!line[x + 1])
		in = -1;
	while (line[++x])
	{
		if ((in == 0 && (line[x] == '0' || line[x] == '2'))
			|| (in == 2 && line[x] == ' '))
			return (-1);
		else if ((in == 0 || in == 2) && line[x] == '1')
			in = 1;
		else if (in == 1 && (line[x] == '0' || line[x] == '2'))
			in = 2;
		else if (in == 1 && line[x] == ' ')
			in = 0;
	}
	if (in == -1)
		return (0);
	else if (in == 2)
		return (-1);
	else
		return (1);
}

static int	check_valid_col(char **map, size_t x)
{
	size_t	y;
	int		in;

	y = 0;
	in = 0;
	while (map[y])
	{
		if ((in == 0 && (map[y][x] == '0' || map[y][x] == '2'))
			|| (in == 2 && map[y][x] == ' '))
			return (0);
		else if ((in == 0 || in == 2) && map[y][x] == '1')
			in = 1;
		else if (in == 1 && (map[y][x] == '0' || map[y][x] == '2'))
			in = 2;
		else if (in == 1 && map[y][x] == ' ')
			in = 0;
		y++;
	}
	if (in == 2)
		return (0);
	else
		return (1);
}

static int	check_valid_map(char **map)
{
	size_t	y;
	size_t	x;
	size_t	width;
	int		prev_ret;
	int		ret;

	y = -1;
	x = -1;
	width = ft_strlen(map[y + 1]);
	prev_ret = 1;
	ret = 0;
	while (map[++y])
	{
		ret = check_valid_line(map[y]);
		if ((prev_ret == 0 && ret == 1) || ret == -1)
			return (0);
		prev_ret = ret;
	}
	while (++x < width)
	{
		if (!check_valid_col(map, x))
			return (0);
	}
	return (1);
}

void	check_valid(t_temp *temp, t_cub3d *data)
{
	if (!check_valid_map_char(temp->map.map))
		free_data_err("invalid character found in map description", temp, data);
	if (!check_valid_map(temp->map.map))
		free_data_err("map is invalid", temp, data);
}
