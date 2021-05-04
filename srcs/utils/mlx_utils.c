/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:29 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:15:08 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <string.h>
#include "struct.h"
#include "error.h"

static void	adjust_res(t_mlx *mlx, t_cub3d *data)
{
	int	screen_x;
	int	screen_y;

	mlx_get_screen_size(mlx->p, &screen_x, &screen_y);
	if (screen_x < data->def.x)
		data->def.x = screen_x;
	if (screen_y < data->def.y)
		data->def.y = screen_y;
}

static int	open_mlx_text(t_mlx *m, t_text *t, t_img *img)
{
	t->img.img = mlx_xpm_file_to_image(m->p, t->path, &t->w, &t->h);
	if (!t->img.img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
	return (1);
}

static int	open_text(t_mlx *m, t_cub3d *d)
{
	if (open_mlx_text(m, &d->txt_sp, &d->txt_sp.img)
		&& open_mlx_text(m, &d->text_n, &d->text_n.img)
		&& open_mlx_text(m, &d->text_s, &d->text_s.img)
		&& open_mlx_text(m, &d->text_w, &d->text_w.img)
		&& open_mlx_text(m, &d->text_e, &d->text_e.img))
		return (1);
	return (0);
}

static int	setup_frame(t_mlx *m, t_cub3d *d, t_img *f)
{
	f->img = mlx_new_image(m->p, (int)d->def.x, (int)d->def.y);
	if (!f->img)
		return (0);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->len, &f->end);
	f->h = (int)d->def.y;
	f->w = (int)d->def.x;
	return (1);
}

void	mlx_setup(t_mlx *m, t_cub3d *d)
{
	m->p = mlx_init();
	if (!m->p)
		free_data_err("fail to init mlx", NULL, d);
	adjust_res(m, d);
	if (!(open_text(m, d)))
		free_data_err("fail to open textures", NULL, d);
	if (d->save != 1)
	{
		m->w = mlx_new_window(m->p, (int)d->def.x, (int)d->def.y, "cub3D");
		if (!m->w)
			free_data_err("fail to create window", NULL, d);
	}
	if (!(setup_frame(m, d, &m->fra)))
		free_data_err("fail to create image", NULL, d);
}
