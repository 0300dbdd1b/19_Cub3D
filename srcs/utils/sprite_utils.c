/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:53 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:15:57 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "utils.h"

int	is_new_sprite(t_sprite *sprite, double x, double y)
{
	while (sprite)
	{
		if (sprite->pos.x == x && sprite->pos.y == y)
			return (0);
		sprite = sprite->next;
	}
	return (1);
}

t_sprite	*create_sprite(double p_x, double p_y, double new_x, double new_y)
{
	t_sprite	*new;

	new = malloc(sizeof(t_sprite));
	if (!new)
		return (NULL);
	new->pos.x = new_x;
	new->pos.y = new_y;
	new->dist = sqrt(pow(p_x - new_x, 2) + pow(p_y - new_y, 2));
	new->angle = round_rad(atan2((new_y - p_y) * -1, new_x - p_x));
	new->next = NULL;
	return (new);
}

t_sprite	*add_sprite(t_sprite *s, t_sprite *new)
{
	t_sprite	*cur;
	t_sprite	*prev;

	if (!s || !new)
		return (NULL);
	cur = s;
	prev = NULL;
	while (cur)
	{
		if (cur->dist <= new->dist)
		{
			new->next = cur;
			if (prev)
				prev->next = new;
			else
				s = new;
			return (s);
		}
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	return (s);
}
