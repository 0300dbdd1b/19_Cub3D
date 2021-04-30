/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:07:42 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/20 21:12:28 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		s_len = 0;
	else
		s_len = s_len - start;
	if (s_len < len)
		len = s_len;
	cpy = malloc(sizeof(*s) * (len + 1));
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, s + start, len + 1);
	return (cpy);
}
