/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:43:54 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/23 13:24:40 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_print(t_map *map)
{
	printf("res: %lu x %lu\n", map->res_x, map->res_y);
	printf("tx NO: [%s]\n", map->tx_no);
	printf("tx SO: [%s]\n", map->tx_so);
	printf("tx WE: [%s]\n", map->tx_we);
	printf("tx EA: [%s]\n", map->tx_ea);
	printf("tx S: [%s]\n", map->tx_s);
	for (t_uint64 i = 0; i < map->height; i++)
	{
		printf("line %03lu - [", i);
		for (t_uint64 j = 0; j < map->width; j++)
		{
			if (map->content[i][j] >= 0)
				printf("%d", map->content[i][j]);
			else
				printf(" ");
		}
		printf("]\n");
	}
}
