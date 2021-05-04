/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:24:33 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:24:35 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

void		check_valid(t_temp *temp, t_cub3d *data);
void		parse_floor(t_temp *temp);
void		parse_ceiling(t_temp *temp);
t_cub3d		*get_data(t_temp *temp);
void		get_map(t_temp *temp, t_cub3d *data);
int			get_pos(char **map, t_cub3d *data);
void		get_no_texture(t_temp *temp, t_cub3d *data);
void		get_so_texture(t_temp *temp, t_cub3d *data);
void		get_we_texture(t_temp *temp, t_cub3d *data);
void		get_ea_texture(t_temp *temp, t_cub3d *data);
void		get_s_texture(t_temp *temp, t_cub3d *data);
void		parse_map(t_temp *temp);
t_cub3d		*cub_parser(char *path);
void		parse_resolution(t_temp *temp);
void		parse_no_texture(t_temp *temp);
void		parse_so_texture(t_temp *temp);
void		parse_we_texture(t_temp *temp);
void		parse_ea_texture(t_temp *temp);
void		parse_s_texture(t_temp *temp);

#endif
