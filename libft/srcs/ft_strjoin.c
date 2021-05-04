/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:50:54 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 16:00:35 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*output;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * len + 1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	ft_strlcat(output, s1, len + 1);
	ft_strlcat(output, s2, len + 1);
	return (output);
}
