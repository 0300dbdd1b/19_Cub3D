/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:05 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:22:07 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	check_path(char *path, char *ext)
{
	size_t	len;
	size_t	ext_len;

	len = ft_strlen(path);
	ext_len = ft_strlen(ext);
	if (ext_len < len)
	{
		if (ft_strcmp(path + (len - ext_len), ext))
			return (0);
	}
	return (1);
}
