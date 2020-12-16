/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:29:37 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/11 16:39:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_dda(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->wall_side = ray->dir.x < 0? 0: 1;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->wall_side = ray->dir.y < 0? 2: 3;
		}
			//sprintf("be check %ld %ld\n", ray->map.x, ray->map.x);
		if (game->map->content[ray->map.x][ray->map.y] == 1)
			ray->hit = 1;
			//printf("af check %ld %ld\n", ray->map.x, ray->map.x);
	}
	if (ray->wall_side < 2)
		ray->wall_dist = (ray->map.x - game->view->pos.x +
		(1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->wall_dist = (ray->map.y - game->view->pos.y +
		(1 - ray->step.y) / 2) / ray->dir.y;
}

void		ray_process(t_ray *ray, t_game *game)
{
	ray_dda(ray, game);
}
