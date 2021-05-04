/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:24:59 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:25:01 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>

typedef struct s_vect
{
	double		x;
	double		y;
	double		len;
}				t_vect;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_img
{
	void		*img;
	int			w;
	int			h;
	void		*addr;
	int			bpp;
	int			len;
	int			end;
}				t_img;

typedef struct s_text
{
	char		*path;
	int			w;
	int			h;
	t_img		img;
}				t_text;

typedef struct s_sprite
{
	t_point		pos;
	double		dist;
	double		angle;
	void		*next;
}				t_sprite;

typedef struct s_map
{
	size_t		w;
	size_t		h;
	char		**map;
}				t_map;

typedef struct s_temp
{
	int			fd;
	char		*line;
	char		*trim;
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			f[3];
	int			c[3];
	t_map		map;
	int			count;
}				t_temp;

typedef struct s_mlx
{
	void		*p;
	void		*w;
	t_img		fra;
}				t_mlx;

typedef struct s_ray
{
	int			up;
	int			left;
	t_point		h_i;
	t_point		v_i;
	t_point		i;
	double		angle;
	double		step_x;
	double		step_y;
	int			dir;
	int			text_dir;
	t_text		*wall;
}				t_ray;

typedef struct s_cub3d
{
	t_mlx		mlx;
	t_point		pos;
	double		fov;
	double		angle;
	t_ray		ray;
	double		step_rad;
	t_map		map;
	t_text		txt_sp;
	t_text		text_n;
	t_text		text_s;
	t_text		text_e;
	t_text		text_w;
	int			color_ceil;
	int			color_floor;
	t_point		def;
	double		*z_buf;
	double		*angle_buf;
	t_sprite	*sprite;
	int			save;
	double		d_to_screen;
}				t_cub3d;

void			init_temp(t_temp *temp);
void			init_cub3d(t_cub3d *data);
void			free_temp(t_temp *temp);
void			free_data(t_cub3d *data);
void			free_map(t_map *map);
void			free_mlx(t_mlx	*mlx);
void			free_sprite(t_sprite *sprite);
void			free_text(t_mlx *m, t_text *t);
void			init_ray(t_ray *ray);
void			init_point(t_point *point);
void			init_map(t_map *map);
void			init_mlx(t_mlx *mlx);
void			init_sprite(t_sprite *s);
void			init_text(t_text *t);

#endif
