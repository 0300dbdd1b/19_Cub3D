/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:24:12 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/08 17:36:28 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buf[_SC_OPEN_MAX][BUFFER_SIZE + 1];
	char		*res;
	int			eof;

	res = 0;
	eof = 1;
	if (fd < 0 || !line || !(malloc_res(&res, buf[fd])))
		return (-1);
	while (eof > 0 && !is_nl_into(buf[fd]))
	{
		eof = get_buffer(fd, buf[fd], BUFFER_SIZE);
		if (eof == -1 || !(malloc_res(&res, buf[fd])))
		{
			free(res);
			return (-1);
		}
	}
	*line = res;
	if (!reset_buffer(buf[fd]) && !eof && !*res)
		return (0);
	return (1);
}
