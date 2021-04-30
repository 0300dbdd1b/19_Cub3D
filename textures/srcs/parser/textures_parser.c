/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:21 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:20:22 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"
#include "error.h"

void	parse_no_texture(t_temp *temp)
{
	char	*line;

	line = temp->trim + 2;
	if (!(*line == ' '))
		free_tmp_err("invalid NO line", temp, 3);
	while (*line == ' ')
		line++;
	temp->north = ft_strdup(line);
	temp->count++;
}

void	parse_so_texture(t_temp *temp)
{
	char	*line;

	line = temp->trim + 2;
	if (!(*line == ' '))
		free_tmp_err("invalid SO line", temp, 3);
	while (*line == ' ')
		line++;
	temp->south = ft_strdup(line);
	temp->count++;
}

void	parse_we_texture(t_temp *temp)
{
	char	*line;

	line = temp->trim + 2;
	if (!(*line == ' '))
		free_tmp_err("invalid WE line", temp, 3);
	while (*line == ' ')
		line++;
	temp->west = ft_strdup(line);
	temp->count++;
}

void	parse_ea_texture(t_temp *temp)
{
	char	*line;

	line = temp->trim + 2;
	if (!(*line == ' '))
		free_tmp_err("invalid EA line", temp, 3);
	while (*line == ' ')
		line++;
	temp->east = ft_strdup(line);
	temp->count++;
}

void	parse_s_texture(t_temp *temp)
{
	char	*line;

	line = temp->trim + 1;
	if (!(*line == ' '))
		free_tmp_err("invalid S line", temp, 3);
	while (*line == ' ')
		line++;
	temp->sprite = ft_strdup(line);
	temp->count++;
}
