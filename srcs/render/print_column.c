/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:37 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:12:41 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "utils.h"

static t_text	*get_wall_text(t_cub3d *data, int text_dir)
{
	if (text_dir == 0)
		return (&data->text_e);
	else if (text_dir == 1)
		return (&data->text_s);
	else if (text_dir == 2)
		return (&data->text_w);
	else if (text_dir == 3)
		return (&data->text_n);
	else
		return (NULL);
}

static int	get_text_col(t_text *text, double new_w, double intersect)
{
	double	ratio_w;
	double	col;
	double	col_size;

	col = 0;
	intersect = intersect - (int)intersect;
	ratio_w = (double)text->w / new_w;
	col_size = 1 / new_w;
	while (intersect >= col_size * (double)(col + 1))
		col++;
	return ((int)(col * ratio_w));
}

static void	print_loop(t_cub3d *d, int *xy_se, double proj, int *text)
{
	int		c;
	double	rat;

	rat = (double)d->ray.wall->h / proj;
	while (xy_se[1] < xy_se[2])
	{
		ft_mlx_pixel_put(&d->mlx, &d->mlx.fra, xy_se, d->color_ceil);
		xy_se[1]++;
	}
	while (xy_se[1] < xy_se[3] && xy_se[1] < (int)d->def.y)
	{
		c = ft_mlx_pixel_get(&d->ray.wall->img, text[0], (int)(text[1] * rat));
		ft_mlx_pixel_put(&d->mlx, &d->mlx.fra, xy_se, c);
		text[1]++;
		xy_se[1]++;
	}
	while (xy_se[1] < (int)d->def.y)
	{
		ft_mlx_pixel_put(&d->mlx, &d->mlx.fra, xy_se, d->color_floor);
		xy_se[1]++;
	}
}

static void	print_text(t_cub3d *d, double proj_size, int x, int text_x)
{
	int		xy_start_end[4];
	int		text[2];

	xy_start_end[0] = x;
	xy_start_end[1] = 0;
	xy_start_end[2] = (int)((d->def.y / 2) - (proj_size / 2));
	xy_start_end[3] = xy_start_end[2] + proj_size;
	text[0] = text_x;
	text[1] = 0;
	while (xy_start_end[2] < 0)
	{
		text[1]++;
		xy_start_end[2]++;
	}
	print_loop(d, xy_start_end, proj_size, text);
}

void	print_column(t_ray *r, t_cub3d *d, int x)
{
	int		text_col;
	double	dist_to_wall;
	double	proj_size;

	dist_to_wall = get_dist(&d->pos, &r->i) * cos(r->angle - d->angle);
	d->z_buf[x] = dist_to_wall;
	if (dist_to_wall < 0.1)
		dist_to_wall = 0.1;
	proj_size = (1 / dist_to_wall) * d->d_to_screen;
	r->wall = get_wall_text(d, r->text_dir);
	if (r->text_dir == 1 || r->text_dir == 3)
		text_col = get_text_col(r->wall, proj_size, r->i.x);
	else
		text_col = get_text_col(r->wall, proj_size, r->i.y);
	print_text(d, proj_size, x, text_col);
}
