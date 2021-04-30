/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:48 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:22:49 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

unsigned char	get_red(int color)
{
	return ((unsigned char)((color >> 16) & 255));
}

unsigned char	get_green(int color)
{
	return ((unsigned char)((color >> 8) & 255));
}

unsigned char	get_blue(int color)
{
	return ((unsigned char)(color & 255));
}
