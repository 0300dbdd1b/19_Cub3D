/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:24 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:22:25 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct.h"

void	ft_mlx_pixel_put(t_mlx *mlx, t_img *img, int *xy, int col)
{
	char	*dst;

	dst = img->addr + (xy[1] * img->len + xy[0] * (img->bpp / 8));
	*(unsigned int *)dst = mlx_get_color_value(mlx->p, col);
}

int	ft_mlx_pixel_get(t_img *img, int x, int y)
{
	int	ret;

	ret = *(int *)(img->addr + (y * img->len + x * (img->bpp / 8)));
	return (ret);
}
