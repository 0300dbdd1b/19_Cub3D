/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:39 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:21:40 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include "struct.h"
#include "utils.h"
#include "error.h"

void	sprite_found(t_cub3d *data, double x, double y)
{
	t_sprite	*new;

	if (is_new_sprite(data->sprite, x, y))
	{
		new = create_sprite(data->pos.x, data->pos.y, x, y);
		if (!new)
			free_data_err(strerror(errno), NULL, data);
		if (data->sprite)
			data->sprite = add_sprite(data->sprite, new);
		else
			data->sprite = new;
	}
}
