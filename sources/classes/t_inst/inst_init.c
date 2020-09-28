/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:37:18 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 13:48:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_inst		inst_init(t_map *map)
{
	t_inst	instance;

	if (!(instance.ptr = mlx_init()))
		err_exit(ERRTYPE_MLX);
	instance.win = win_init(instance.ptr, map->res_x, map->res_y);
	return (instance);
}
