/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:37:18 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:09:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_display		display_init(t_map *map)
{
	t_display	display;

	if (!(display.ptr = mlx_init()))
		err_exit(ERRTYPE_MLX);
	display.win = win_init(display.ptr, map->res_x, map->res_y);
	return (display);
}
