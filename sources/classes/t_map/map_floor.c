/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:58:55 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/19 18:00:11 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	map_floor(t_map *map, t_fvect v)
{
	t_vect	roundv;
	if (v.x >= 0 && v.x < map->height && v.y >= 0 && v.y < map->width)
	{
		roundv = vect_fromf(v);
		if (map->content[roundv.x][roundv.y] == 0)
			return (TRUE);
	}
	return (FALSE);
}