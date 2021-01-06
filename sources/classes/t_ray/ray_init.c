/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:18:31 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/06 17:48:10 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initial_calc(t_ray *ray, t_game *game)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (game->view->pos.x - ray->map.x)
		* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - game->view->pos.x)
		* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (game->view->pos.y - ray->map.y)
		* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - game->view->pos.y)
		* ray->delta_dist.y;
	}
}

t_ray		*ray_init(t_frame *frame, int screen_x)
{
	t_ray	*ray;

	if (!(ray = ft_calloc(1, sizeof(t_ray))))
		err_exit(ERRTYPE_NOMEM);
	ray->screen_x = screen_x;
	ray->cam_x = 2 * ray->screen_x / (double)frame->game->map->res_x - 1;
	ray->dir.x = frame->game->view->dir.x + frame->game->view->fov.x
	* ray->cam_x;
	ray->dir.y = frame->game->view->dir.y + frame->game->view->fov.y
	* ray->cam_x;
	ray->map.x = (int)frame->game->view->pos.x;
	ray->map.y = (int)frame->game->view->pos.y;
	if (ray->dir.y == 0)
		ray->delta_dist.x = 0;
	else
		ray->delta_dist.x = (ray->dir.x == 0) ? 1 : fabs(1 / ray->dir.x);
	if (ray->dir.x == 0)
		ray->delta_dist.y = 0;
	else
		ray->delta_dist.y = (ray->dir.y == 0) ? 1 : fabs(1 / ray->dir.y);
	ray->hit = 0;
	initial_calc(ray, frame->game);
	return (ray);
}
