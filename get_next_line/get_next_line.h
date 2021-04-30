/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:14:41 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/08 18:13:30 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		get_buffer(int fd, char *buf, size_t size);
size_t	ft_strnllen(char *str);
int		malloc_res(char **res, char *buf);
int		is_nl_into(char *str);
int		reset_buffer(char *buf);

#endif
