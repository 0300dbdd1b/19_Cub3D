/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:41 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:15:26 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <string.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include "utils.h"
#include "error.h"
#include "struct.h"

static void	fill_img(t_mlx *m, t_img *new, t_text *t)
{
	int		xy[2];
	int		old[2];
	int		color;
	double	ratio[2];

	xy[1] = 0;
	ratio[0] = (double)t->h / (double)new->h;
	ratio[1] = (double)t->w / (double)new->w;
	while (xy[1] < new->h)
	{
		xy[0] = 0;
		while (xy[0] < new->w)
		{
			old[0] = (int)(floor((double)xy[0]) * ratio[0]);
			old[1] = (int)(floor((double)xy[1]) * ratio[1]);
			color = ft_mlx_pixel_get(&t->img, old[0], old[1]);
			ft_mlx_pixel_put(m, new, xy, color);
			xy[0]++;
		}
		xy[1]++;
	}
}

t_img	*resize_image(t_cub3d *d, t_text *t, int w, int h)
{
	t_img	*n;

	n = malloc(sizeof(t_img));
	if (!n)
		free_data_err(strerror(errno), NULL, d);
	n->h = h;
	n->w = w;
	n->img = mlx_new_image(d->mlx.p, w, h);
	if (!n->img)
	{
		free(n);
		free_data_err("mlx fail to create image", NULL, d);
	}
	n->addr = mlx_get_data_addr(n->img, &n->bpp, &n->len, &n->end);
	fill_img(&d->mlx, n, t);
	return (n);
}
