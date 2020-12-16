/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:55:08 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/14 17:30:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_print(t_map *map)
{
	printf("res: %d x %d\n", map->res_x, map->res_y);
	printf("tx NO: [%s]\n", map->tx_no->path);
	printf("tx SO: [%s]\n", map->tx_so->path);
	printf("tx WE: [%s]\n", map->tx_we->path);
	printf("tx EA: [%s]\n", map->tx_ea->path);
	printf("tx S: [%s]\n", map->tx_s->path);
	printf("posx: %i, posy: %i\n", map->pos_x, map->pos_y);
	for (t_uint64 i = 0; i < map->height; i++)
	{
		printf("line %03lu - [", i);
		for (t_uint64 j = 0; j < map->width; j++)
		{
			if ((int)i == map->pos_y && (int)j == map->pos_x)
				printf("X");
			else if (map->content[i][j] >= 0)
				printf("%d", map->content[i][j]);
			else
				printf(" ");
		}
		printf("]\n");
	}
	printf("floor:\n");
	rgb_print(map->cl_floor);
	printf("ceiling:\n");
	rgb_print(map->cl_ceiling);
}
