/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:04 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:11:38 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <errno.h>
#include <string.h>
#include "libft.h"
#include "struct.h"
#include "utils.h"
#include "error.h"

void	get_no_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->north[i])
	{
		if (temp->north[i] == ' ')
			space = i;
		if (space > 0 && temp->north[i] != ' ')
			free_data_err("NO texture contains too many arguments", temp, data);
		i++;
	}
	data->text_n.path = ft_strtrim(temp->north, " ");
	if (!data->text_n.path)
		free_data_err(strerror(errno), temp, data);
}

void	get_so_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->south[i])
	{
		if (temp->south[i] == ' ')
			space = i;
		if (space > 0 && temp->south[i] != ' ')
			free_data_err("SO texture contains too many arguments", temp, data);
		i++;
	}
	data->text_s.path = ft_strtrim(temp->south, " ");
	if (!data->text_s.path)
		free_data_err(strerror(errno), temp, data);
}

void	get_we_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->west[i])
	{
		if (temp->west[i] == ' ')
			space = i;
		if (space > 0 && temp->west[i] != ' ')
			free_data_err("WE texture contains too many arguments", temp, data);
		i++;
	}
	data->text_w.path = ft_strtrim(temp->west, " ");
	if (!data->text_w.path)
		free_data_err(strerror(errno), temp, data);
}

void	get_ea_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->east[i])
	{
		if (temp->east[i] == ' ')
			space = i;
		if (space > 0 && temp->east[i] != ' ')
			free_data_err("EA texture contains too many arguments", temp, data);
		i++;
	}
	data->text_e.path = ft_strtrim(temp->east, " ");
	if (!data->text_e.path)
		free_data_err(strerror(errno), temp, data);
}

void	get_s_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->sprite[i])
	{
		if (temp->sprite[i] == ' ')
			space = i;
		if (space > 0 && temp->sprite[i] != ' ')
			free_data_err("S texture contains too many arguments", temp, data);
		i++;
	}
	data->txt_sp.path = ft_strtrim(temp->sprite, " ");
	if (!data->txt_sp.path)
		free_data_err(strerror(errno), temp, data);
}
