/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:25:06 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:25:07 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

int				check_path(char *path, char *ext);
double			ft_abs(double val);
double			get_dist(t_point *f, t_point *t);
void			ft_mlx_pixel_put(t_mlx *mlx, t_img *img, int *xy, int col);
int				ft_mlx_pixel_get(t_img *img, int x, int y);
void			mlx_setup(t_mlx *m, t_cub3d *d);
double			deg2rad(double deg);
double			rad2deg(double rad);
double			round_rad(double rad);
int				is_greater_angle(double base, double cmp);
t_img			*resize_image(t_cub3d *d, t_text *t, int w, int h);
int				rgb_to_int(int r, int g, int b);
unsigned char	get_red(int color);
unsigned char	get_green(int color);
unsigned char	get_blue(int color);
int				is_new_sprite(t_sprite *sprite, double x, double y);
t_sprite		*add_sprite(t_sprite *s, t_sprite *new);
t_sprite		*create_sprite(double p_x, double p_y,
					double new_x, double new_y);

#endif
