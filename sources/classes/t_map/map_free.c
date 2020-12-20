/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:38:45 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/19 10:51:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_free(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		free(map->content[i]);
		i++;
	}
	ft_lstclear(&map->sprites, &sprite_free);
	free(map->content);
	free(map->tx_no);
	free(map->tx_so);
	free(map->tx_we);
	free(map->tx_ea);
	free(map);
}
