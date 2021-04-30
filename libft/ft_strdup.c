/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:07:10 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/02/12 16:56:17 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s) + 1;
	cpy = malloc(sizeof(*s) * len);
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, s, len);
	return (cpy);
}
