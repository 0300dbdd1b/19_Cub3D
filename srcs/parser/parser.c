/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:16 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:11:58 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include "struct.h"
#include "error.h"
#include "utils.h"

void	check_only_space(t_temp *temp)
{
	if (temp->line[0] == ' ')
		free_tmp_err("invalid line found", temp, 3);
}

static int	get_arg(t_temp *temp)
{
	if (!ft_strncmp(temp->trim, "R", 1))
		parse_resolution(temp);
	else if (!ft_strncmp(temp->trim, "NO", 2))
		parse_no_texture(temp);
	else if (!ft_strncmp(temp->trim, "SO", 2))
		parse_so_texture(temp);
	else if (!ft_strncmp(temp->trim, "WE", 2))
		parse_we_texture(temp);
	else if (!ft_strncmp(temp->trim, "EA", 2))
		parse_ea_texture(temp);
	else if (!ft_strncmp(temp->trim, "S", 1))
		parse_s_texture(temp);
	else if (!ft_strncmp(temp->trim, "F", 1))
		parse_floor(temp);
	else if (!ft_strncmp(temp->trim, "C", 1))
		parse_ceiling(temp);
	else if (!ft_strncmp(temp->trim, "1", 1) || !ft_strncmp(temp->trim, "0", 1))
		return (0);
	else
		check_only_space(temp);
	return (1);
}

static void	parse_args(t_temp *temp)
{
	int	is_map;
	int	ret;

	is_map = 0;
	ret = ft_get_next_line(temp->fd, &(temp->line));
	while (!is_map && ret)
	{
		if (ret == -1)
			free_tmp_err(strerror(errno), temp, 0);
		temp->trim = ft_strtrim(temp->line, " ");
		if (!temp->trim)
			free_tmp_err(strerror(errno), temp, 1);
		if (!get_arg(temp))
			is_map = 1;
		if (!is_map)
			free(temp->line);
		if (!is_map)
			ret = ft_get_next_line(temp->fd, &(temp->line));
		free(temp->trim);
	}
	if (!is_map)
		free_tmp_err("no map has been found", temp, 1);
	parse_map(temp);
}

t_cub3d	*cub_parser(char *path)
{
	t_temp	temp;
	t_cub3d	*data;

	init_temp(&temp);
	if (!check_path(path, ".cub"))
		ft_error("file must end with .cub");
	temp.fd = open(path, O_RDONLY);
	if (temp.fd == -1)
		ft_error(strerror(errno));
	parse_args(&temp);
	if (close(temp.fd))
		free_tmp_err(strerror(errno), &temp, 0);
	if (temp.count > 8)
		free_tmp_err("some lines are doubled in file", &temp, 0);
	temp.fd = -1;
	data = get_data(&temp);
	data->z_buf = ft_calloc(data->def.x, sizeof(double));
	if (!data->z_buf)
		free_data_err(strerror(errno), NULL, data);
	data->angle_buf = ft_calloc(data->def.x, sizeof(double));
	if (!data->angle_buf)
		free_data_err(strerror(errno), NULL, data);
	return (data);
}
