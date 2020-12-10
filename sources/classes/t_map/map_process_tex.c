/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:23:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/09 17:58:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_process_tex(t_map *map, void *mlx_ptr)
{
	texture_process(map->tx_no, mlx_ptr);
	texture_process(map->tx_ea, mlx_ptr);
	texture_process(map->tx_so, mlx_ptr);
	texture_process(map->tx_we, mlx_ptr);
	texture_process(map->tx_s, mlx_ptr);
}
