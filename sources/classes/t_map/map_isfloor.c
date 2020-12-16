/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isfloor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:58:55 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/14 17:52:24 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	map_isfloor(t_map *map, t_fvect v)
{
	t_vect	round_pos;

	round_pos = vect_init((t_int64)floor(v.x), (t_int64)floor(v.y));
	if (round_pos.x < 0 || (uint64_t)round_pos.x >= map->width)
		return (FALSE);
	if (round_pos.y < 0 || (uint64_t)round_pos.y >= map->height)
		return (FALSE);
	if (map->content[round_pos.y][round_pos.x] != 0)
		return (FALSE);
	return (TRUE);
}