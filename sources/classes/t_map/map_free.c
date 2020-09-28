/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:38:45 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 11:42:46 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*map_free(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		free(map->content[i]);
		i++;
	}
	free(map->content);
	free(map->tx_no);
	free(map->tx_so);
	free(map->tx_we);
	free(map->tx_ea);
	free(map);
	return (NULL);
}
