/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:16:13 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 17:30:08 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../../includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX _SC_OPEN_MAX
# endif

int		get_buffer(int fd, char *buf, size_t size);
size_t	ft_strnllen(char *str);
int		malloc_res(char **res, char *buf);
int		is_nl_into(char *str);
int		reset_buffer(char *buf);
int		ft_get_next_line(int fd, char **line);

#endif
