/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_frame_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/04 18:35:36 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void beta_frame_loop(t_game *game)
{
	int i;
	t_frame *frame;
	t_ray	*ray;

	i = 0;
	frame = frame_init(game);

	while (i < game->map->res_x)
	{
		ray = ray_init(frame, i);
		if (ray->dir.x < 0)
		{
			ray->step.x = -1;
			ray->side_dist.x = (game->view->pos.x - ray->map.x) * ray->delta_dist.x;
		}
		else
		{
			ray->step.x = 1;
			ray->side_dist.x = (ray->map.x + 1.0 - game->view->pos.x) * ray->delta_dist.x;
		}
		if (ray->dir.y < 0)
		{
			ray->step.y = -1;
			ray->side_dist.y = (game->view->pos.y - ray->map.y) * ray->delta_dist.y;
		}
		else
		{
			ray->step.y = 1;
			ray->side_dist.y = (ray->map.y + 1.0 - game->view->pos.y) * ray->delta_dist.y;
		}
		while (ray->hit == 0)
		{
			if (ray->side_dist.x < ray->side_dist.y)
			{
				ray->side_dist.x += ray->delta_dist.x;
				ray->map.x += ray->step.x;
			ray->wall_side = 0;
			}
			else
			{
				ray->side_dist.y += ray->delta_dist.y;
				ray->map.y += ray->step.y;
			ray->wall_side = 1;
			}
			if (game->map->content[ray->map.x][ray->map.y] > 0)
				ray->hit = 1;
		}
		if (ray->wall_side == 0)
			ray->wall_dist = (ray->map.x - game->view->pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
		else
			ray->wall_dist = (ray->map.y - game->view->pos.y + (1 - ray->step.y) / 2) / ray->dir.y;

		int lineHeight = (int)(game->map->res_y / ray->wall_dist);

		int drawStart = -lineHeight / 2 + game->map->res_y / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + game->map->res_y / 2;
		if (drawEnd >= game->map->res_y)
			drawEnd = game->map->res_y - 1;

		t_rgb color;
		color = rgb_init(255, 0, 0);

		if (ray->wall_side == 1)
		{
			color.r /= 2;
			color.g /= 2;
			color.b /= 2;
		}

		for (int y = drawStart; y < drawEnd; y++)
		{
			frame_put_pixel(frame, vect_init(i, y), color);
		}
		//frame_put_line(frame, vect_init(i, drawStart), lineHeight, color);
		i++;
	}

	frame_push(frame);
	frame_free(frame);
}
