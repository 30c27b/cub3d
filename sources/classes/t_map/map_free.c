/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:38:45 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/12 12:30:29 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_free(t_map *map, void *mlx_ptr)
{
	size_t	i;

	i = 0;
	while (i < map->height)
		free(map->content[i++]);
	ft_lstclear(&map->sprites, &sprite_free);
	free(map->content);
	texture_free(map->tx_no, mlx_ptr);
	texture_free(map->tx_so, mlx_ptr);
	texture_free(map->tx_we, mlx_ptr);
	texture_free(map->tx_ea, mlx_ptr);
	texture_free(map->tx_s, mlx_ptr);
	free(map);
}
