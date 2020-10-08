/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:29:12 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 15:36:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_view		*view_init(t_map *map)
{
	t_view	*view;

	(void)map;
	if (!(view = ft_calloc(1, sizeof(t_view))))
		err_exit(ERRTYPE_NOMEM);
	view->dir= fvect_init(-1, 0);
	view->fov = fvect_init(0, 0.66);
	view->pos = fvect_init(map->pos_x, map->pos_y);
	return (view);
}
