/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:29:52 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 16:45:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_dda(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->wall_side = ray->dir.x < 0 ? 0 : 1;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->wall_side = ray->dir.y < 0 ? 2 : 3;
		}
		if (game->map->content[ray->map.y][ray->map.x] == 1)
			ray->hit = 1;
	}
	if (ray->wall_side < 2)
		ray->wall_dist = (ray->map.x - game->view->pos.x +
		(1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->wall_dist = (ray->map.y - game->view->pos.y +
		(1 - ray->step.y) / 2) / ray->dir.y;
	ray->line_h = (int)(game->map->res_y / ray->wall_dist);
	ray->draw_s = -ray->line_h / 2 + game->map->res_y / 2;
}
