/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:27:22 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/20 21:33:07 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(sizeof(*res) * (s1_len + s2_len + 1));
	if (!res)
		return (0);
	res[0] = 0;
	ft_strncat(res, s1, s1_len);
	ft_strncat(res, s2, s2_len);
	return (res);
}
