/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_frame_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/30 20:39:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void beta_frame_loop(t_game *game)
{
	size_t i;
	t_frame *frame;

	i = 0;
	frame = frame_init(game);

	while (i < (size_t)game->map->res_x)
	{
		double cameraX = 2 * i / (double)game->map->res_x - 1;
		double rayDirX = game->view->dir.x + game->view->fov.x * cameraX;
		double rayDirY = game->view->dir.y + game->view->fov.y * cameraX;
		int mapX = (int)game->view->pos.x;
		int mapY = (int)game->view->pos.y;

		double sideDistX;
		double sideDistY; 

		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->view->pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->view->pos.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->view->pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->view->pos.y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (game->map->content[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - game->view->pos.x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - game->view->pos.y + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(game->map->res_y / perpWallDist);

		int drawStart = -lineHeight / 2 + game->map->res_y / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + game->map->res_y / 2;
		if (drawEnd >= game->map->res_y)
			drawEnd = game->map->res_y - 1;

		t_rgb color;
		color = rgb_init(255, 0, 0);

		if (side == 1)
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
