/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:55 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:21:56 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->map)
	{
		while (i <= map->h)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->p && mlx->w)
		mlx_destroy_window(mlx->p, mlx->w);
	if (mlx->p && mlx->fra.img)
		mlx_destroy_image(mlx->p, mlx->fra.img);
}

void	free_sprite(t_sprite *sprite)
{
	t_sprite	*next;

	while (sprite)
	{
		next = sprite->next;
		free(sprite);
		sprite = next;
	}
}

void	free_text(t_mlx *m, t_text *t)
{
	if (t->path)
		free(t->path);
	if (t->img.img)
		mlx_destroy_image(m->p, t->img.img);
}
