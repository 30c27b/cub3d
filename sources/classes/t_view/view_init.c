/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:29:12 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/16 16:02:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_direction(t_view *view, t_map *map)
{
	if (map->direction == 'N')
	{
		view->dir= fvect_init(0, -1);
		view->fov = fvect_init(FOV, 0);
	}
	else if (map->direction == 'S')
	{
		view->dir= fvect_init(0, 1);
		view->fov = fvect_init(-FOV, 0);
	}
	else if (map->direction == 'E')
	{
		view->dir= fvect_init(1, 0);
		view->fov = fvect_init(0, FOV);
	}
	else if (map->direction == 'W')
	{
		view->dir= fvect_init(-1, 0);
		view->fov = fvect_init(0, -FOV);
	}
	else
		err_exit(ERRTYPE_BADMAP);
}

t_view		*view_init(t_map *map)
{
	t_view	*view;

	if (!(view = ft_calloc(1, sizeof(t_view))))
		err_exit(ERRTYPE_NOMEM);
	view->pos = fvect_init(map->pos_x + 0.5, map->pos_y + 0.5);
	view->keyflag = 0b00000000;
	parse_direction(view, map);
	return (view);
}
