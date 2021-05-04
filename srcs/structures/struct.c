/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:59 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:13:51 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	init_point(t_point *point)
{
	point->x = -1;
	point->y = -1;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->p = NULL;
	mlx->w = NULL;
	mlx->fra.img = NULL;
	mlx->fra.addr = NULL;
	mlx->fra.bpp = 0;
	mlx->fra.len = 0;
	mlx->fra.end = 0;
}

void	init_text(t_text *t)
{
	t->path = NULL;
	t->w = 0;
	t->h = 0;
	t->img.img = NULL;
	t->img.addr = NULL;
	t->img.bpp = 0;
	t->img.len = 0;
	t->img.end = 0;
}

void	init_ray(t_ray *ray)
{
	ray->up = 0;
	ray->left = 0;
	init_point(&ray->h_i);
	init_point(&ray->v_i);
	init_point(&ray->i);
	ray->step_x = 0;
	ray->step_y = 0;
	ray->angle = 0;
	ray->text_dir = 0;
	ray->dir = 0;
}
