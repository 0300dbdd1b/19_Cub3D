/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:33 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:13:09 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include <stdlib.h>
#include "struct.h"
#include "sprite.h"
#include "utils.h"

static void	print_sprite_col(t_cub3d *d, t_img *img, int x_img, int x)
{
	int	xy[2];
	int	y_img;
	int	start;
	int	color;

	xy[0] = x;
	xy[1] = 0;
	y_img = 0;
	start = (d->def.y / 2) - (img->h / 2);
	while (xy[1] < start)
		xy[1]++;
	while (xy[1] < 0)
	{
		xy[1]++;
		y_img++;
	}
	while (y_img < img->h && xy[1] < d->def.y)
	{
		color = ft_mlx_pixel_get(img, x_img, y_img);
		if (color > 0)
			ft_mlx_pixel_put(&d->mlx, &d->mlx.fra, xy, color);
		xy[1]++;
		y_img++;
	}
}

static void	print_sprite_to_screen(t_cub3d *d, t_img *img, int x, double dist)
{
	int	x_img;

	x_img = 0;
	x -= img->w / 2;
	while (x < 0)
	{
		x++;
		x_img++;
	}
	while (x < d->def.x && x_img < img->w)
	{
		if (d->z_buf[x] > dist)
		{
			print_sprite_col(d, img, x_img, x);
		}
		x_img++;
		x++;
	}
}

void	print_sprite(t_cub3d *d)
{
	t_sprite	*cur;
	int			x;
	t_img		*img;
	int			proj_hw[2];
	double		sprite_h;

	sprite_h = 1;
	cur = d->sprite;
	while (cur)
	{
		x = (int)find_sprite_col(cur, d);
		proj_hw[0] = (int)((sprite_h / cur->dist) * d->d_to_screen);
		proj_hw[1] = (int)(d->txt_sp.w * ((double)proj_hw[0] / d->txt_sp.h));
		if (proj_hw[0] > 0 && proj_hw[1] > 0)
		{
			img = resize_image(d, &d->txt_sp, proj_hw[1], proj_hw[0]);
			print_sprite_to_screen(d, img, x, cur->dist);
			mlx_destroy_image(d->mlx.p, img->img);
			free(img);
		}
		cur = cur->next;
	}
}
