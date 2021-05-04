/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:24:53 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:24:55 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "struct.h"

double	find_sprite_col(t_sprite *s, t_cub3d *d);
void	print_sprite(t_cub3d *d);
void	sprite_found(t_cub3d *data, double x, double y);

#endif
