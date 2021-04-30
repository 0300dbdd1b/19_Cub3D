/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:19:19 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/25 14:19:41 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "error.h"
#include "libft.h"

static int	get_num(int *num, char *line)
{
	*num = ft_atoi(line);
	if (*line == '+' || *line == '-' || !(*num))
		return (0);
	return (1);
}

static int	fill_res(char *line, t_temp *temp)
{
	if (!(*line == ' '))
		return (0);
	while (*line == ' ')
		line++;
	if (!get_num(&temp->x, line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (!(*line == ' '))
		return (0);
	while (*line == ' ')
		line++;
	if (!get_num(&temp->y, line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (*line)
	{
		if (!(*line == ' '))
			return (0);
		line++;
	}
	return (1);
}

void	parse_resolution(t_temp *temp)
{
	char	*line;

	line = temp->trim + 1;
	if (!fill_res(line, temp))
		free_tmp_err("invalid R line", temp, 3);
	temp->count++;
}
