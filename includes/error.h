/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:24:12 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:24:13 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "struct.h"

void	ft_error(char *error);
void	free_tmp_err(char *error, t_temp *temp, int select);
void	free_data_err(char *error, t_temp *temp, t_cub3d *data);

#endif
