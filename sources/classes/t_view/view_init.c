/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:29:12 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/10 18:05:08 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_direction(t_view *view, t_map *map)
{
	if (map->direction == 'N')
	{
		view->dir= fvect_init(-1, 0);
		view->fov = fvect_init(0, 0.66);
	}
	else if (map->direction == 'S')
	{
		view->dir= fvect_init(1, 0);
		view->fov = fvect_init(0, -0.66);
	}
	else if (map->direction == 'E')
	{
		view->dir= fvect_init(0, 1);
		view->fov = fvect_init(0.66, 0);
	}
	else if (map->direction == 'W')
	{
		view->dir= fvect_init(0, -1);
		view->fov = fvect_init(-0.66, 0);
	}
	else
		err_exit(ERRTYPE_BADMAP);
}

t_view		*view_init(t_map *map)
{
	t_view	*view;

	if (!(view = ft_calloc(1, sizeof(t_view))))
		err_exit(ERRTYPE_NOMEM);
	view->pos = fvect_init(map->pos_x, map->pos_y);
	view->keyflag = 0b00000000;
	parse_direction(view, map);
	return (view);
}
