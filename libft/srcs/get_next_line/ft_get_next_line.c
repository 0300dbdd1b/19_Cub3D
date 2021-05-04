/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:20:30 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 17:05:11 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

int	ft_get_next_line(int fd, char **line)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
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
