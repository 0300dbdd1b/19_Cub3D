/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:24:40 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:24:42 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "struct.h"

int		check_h_hit(t_cub3d *d, t_ray *ray, t_map *map);
int		check_v_hit(t_cub3d *d, t_ray *ray, t_map *map);
int		check_hit_loop(t_ray *ray, t_cub3d *data,
			int (*f)(t_cub3d *data, t_ray *ray, t_map *map));
void	find_intersection(t_ray *ray, t_cub3d *data);
void	print_column(t_ray *r, t_cub3d *d, int x);
int		render(t_cub3d *data);
void	render_no_window(t_cub3d *data);

#endif
