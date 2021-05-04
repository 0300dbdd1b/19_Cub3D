/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:48 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/05/04 17:15:46 by naddino          ###   ########.fr       */
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
