/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:18:31 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/04 18:25:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray*		ray_init(t_frame* frame, int w)
{
	t_ray*	ray;

	if (!(ray = ft_calloc(1, sizeof(t_ray))))
		err_exit(ERRTYPE_NOMEM);
	ray->cam_x = 2 * w / (double)frame->game->map->res_x - 1;
	ray->dir.x = frame->game->view->dir.x + frame->game->view->fov.x * ray->cam_x;
	ray->dir.y = frame->game->view->dir.y + frame->game->view->fov.y * ray->cam_x;
	ray->map.x = (int)frame->game->view->pos.x;
	ray->map.y = (int)frame->game->view->pos.y;
	ray->delta_dist.x = (ray->dir.y == 0) ? 0 : ((ray->dir.x == 0) ? 1 : fabs(1 / ray->dir.x));
	ray->delta_dist.y = (ray->dir.x == 0) ? 0 : ((ray->dir.y == 0) ? 1 : fabs(1 / ray->dir.y));
	ray->hit = 0;
	return (ray);
}
