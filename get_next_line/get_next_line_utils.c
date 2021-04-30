/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:24:27 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/08 17:43:41 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_buffer(int fd, char *buf, size_t size)
{
	ssize_t	len;

	len = read(fd, buf, size);
	if (len == -1)
		return (-1);
	buf[len] = 0;
	return ((len != 0));
}

size_t	ft_strnllen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	malloc_res(char **res, char *buf)
{
	char	*new;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	new = malloc(sizeof(**res) * (ft_strnllen(*res) + ft_strnllen(buf) + 1));
	if (!new)
		return (0);
	while (*res && (*res)[i])
	{
		new[i] = (*res)[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
	{
		new[i] = buf[j];
		j++;
		i++;
	}
	new[i] = 0;
	if (*res)
		free(*res);
	*res = new;
	return (1);
}

int	is_nl_into(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	reset_buffer(char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		buf[0] = 0;
		return (0);
	}
	while (buf[j + i])
	{
		buf[j] = buf[j + i + 1];
		j++;
	}
	return (1);
}
