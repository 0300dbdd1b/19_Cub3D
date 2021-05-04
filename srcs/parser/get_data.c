/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:19:34 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:11:20 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "struct.h"
#include "utils.h"
#include "error.h"

static void	check_missing_data(t_temp *temp)
{
	if (temp->x == 0 || temp->y == 0)
		free_tmp_err("resolution is missing", temp, 0);
	if (!temp->north || !temp->south
		|| !temp->west || !temp->east || !temp->sprite)
		free_tmp_err("a texture is missing", temp, 0);
	if (temp->f[0] == -1)
		free_tmp_err("floor is missing", temp, 0);
	if (temp->c[0] == -1)
		free_tmp_err("ceiling is missing", temp, 0);
}

static void	get_resolution(t_temp *temp, t_cub3d *data)
{
	if (temp->x < 0)
		free_data_err("invalid horizontal resolution", temp, data);
	if (temp->y < 0)
		free_data_err("invalid vertical resolution", temp, data);
	data->def.x = temp->x;
	data->def.y = temp->y;
}

static void	get_textures(t_temp *temp, t_cub3d *data)
{
	get_no_texture(temp, data);
	get_so_texture(temp, data);
	get_we_texture(temp, data);
	get_ea_texture(temp, data);
	get_s_texture(temp, data);
}

static void	get_fc(t_temp *temp, t_cub3d *data)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (temp->c[i] < 0 || temp->c[i] > 255)
			free_data_err("invalid RGB values for ceiling", temp, data);
		if (temp->f[i] < 0 || temp->f[i] > 255)
			free_data_err("invalid RGB values for floor", temp, data);
		i++;
	}
	data->color_floor = rgb_to_int(temp->f[0], temp->f[1], temp->f[2]);
	data->color_ceil = rgb_to_int(temp->c[0], temp->c[1], temp->c[2]);
}

t_cub3d	*get_data(t_temp *temp)
{
	t_cub3d	*data;

	check_missing_data(temp);
	data = malloc(sizeof(*data));
	if (!data)
		free_tmp_err(strerror(errno), temp, 0);
	init_cub3d(data);
	get_resolution(temp, data);
	get_textures(temp, data);
	get_fc(temp, data);
	get_map(temp, data);
	free_temp(temp);
	return (data);
}
