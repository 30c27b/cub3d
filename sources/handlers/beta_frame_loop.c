/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_frame_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/10/08 16:03:41 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

void				beta_frame_loop(t_game *game)
{
	t_frame	*frame;

	frame = frame_init(game);

	for (int x = 0; x < game->map->res_x; x++)
	{
		double cameraX = (2 * x) / ((double)game->map->res_x - 1);
		double rayDirX = game->view->dir.x + (planeX * cameraX);
		double rayDirY = game->view->dir.y + (planeY * cameraX);

		int mapX = (int)game->map->pos_x;
		int mapY = (int)game->map->pos_y;

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
			sideDistX = (game->map->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->map->pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->map->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->map->pos_y) * deltaDistY;
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
			if (game->map->content[mapX][mapY] > 0) hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - game->map->pos_x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - game->map->pos_y + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(800 / perpWallDist);

		int drawStart = -lineHeight / 2 + game->map->res_y / 2;
		if(drawStart < 0) drawStart = 0;

		int drawEnd = lineHeight / 2 + game->map->res_y / 2;
		if(drawEnd >= game->map->res_y)drawEnd = game->map->res_y - 1;

		t_rgb	color = rgb_init(200, 78, 100);
		if (side == 1)
			color = rgb_init(0, 200, 50);

		frame_put_line(frame, vect_init(x, drawStart), lineHeight, color);
	}
	frame_push(frame);
	frame_free(frame);
}