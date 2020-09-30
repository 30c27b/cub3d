/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:37:18 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 11:19:52 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_display		*display_init(t_map *map)
{
	t_display	*display;
	int			screen_x;
	int			screen_y;

	if (!(display = ft_calloc(1, sizeof(t_display))))
		err_exit(ERRTYPE_NOMEM);
	if (!(display->mlx_ptr = mlx_init()))
		err_exit(ERRTYPE_MLX);
	mlx_get_screen_size(display->mlx_ptr, &screen_x, &screen_y);
	map->res_x = map->res_x < screen_x ? map->res_x : screen_x;
	map->res_y = map->res_y < screen_y ? map->res_y : screen_y;
	if (!(display->win_ptr = mlx_new_window(display->mlx_ptr, map->res_x, map->res_y, C3D_TITLE)))
		err_exit(ERRTYPE_MLX);
	return (display);
}
