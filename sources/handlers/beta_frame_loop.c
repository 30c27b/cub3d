/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_frame_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/19 17:58:00 by ancoulon         ###   ########.fr       */
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
		//calculate ray position and direction
		double cameraX = 2 * i / (double)game->map->res_x - 1; //x-coordinate in camera space
		double rayDirX = game->view->dir.x + game->view->fov.x * cameraX;
		double rayDirY = game->view->dir.y + game->view->fov.y * cameraX;
		//which box of the map we're in
		int mapX = (int)game->view->pos.x;
		int mapY = (int)game->view->pos.y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY; 

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side;	 //was a NS or a EW wall hit?
		//calculate step and initial sideDist
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
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
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
			//Check if ray has hit a wall
			if (game->map->content[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (mapX - game->view->pos.x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - game->view->pos.y + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(game->map->res_y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + game->map->res_y / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + game->map->res_y / 2;
		if (drawEnd >= game->map->res_y)
			drawEnd = game->map->res_y - 1;

		//choose wall color
		t_rgb color;
		// switch(worldMap[mapX][mapY])
		// {
		//   case 1:  color = rgb_init(255, 0, 0);    break; //red
		//   case 2:  color = rgb_init(0, 255, 0); //green
		//   case 3:  color = rgb_init(0, 0, 255);   break; //blue
		//   case 4:  color = rgb_init(255, 255, 255);  break; //white
		//   default: color = rgb_init(255, 255, 0); break; //yellow
		// }

		color = rgb_init(255, 0, 0);

		//give x and y sides different brightness
		if (side == 1)
		{
			color.r /= 2;
			color.g /= 2;
			color.b /= 2;
		}

		//draw the pixels of the stripe as a vertical line
		for (int y = drawStart; y < drawEnd; y++)
		{
			frame_put_pixel(frame, vect_init(i, y), color);
		}
		i++;
	}

	frame_push(frame);
	frame_free(frame);
}
	// double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	// void				old_beta_frame_loop(t_game *game)
	// {
	// 	t_frame	*frame;

	// 	frame = frame_init(game);

	// 	for (int x = 0; x < game->map->res_x; x++)
	// 	{
	// 		double cameraX = (2 * x) / ((double)game->map->res_x - 1);
	// 		double rayDirX = game->view->dir.x + (planeX * cameraX);
	// 		double rayDirY = game->view->dir.y + (planeY * cameraX);

	// 		int mapX = (int)game->view->pos.x;
	// 		int mapY = (int)game->view->pos.y;

	// 		double sideDistX;
	// 		double sideDistY;

	// 		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
	// 		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
	// 		double perpWallDist;

	// 		int stepX;
	// 		int stepY;

	// 		int hit = 0;
	// 		int side;

	// 		if (rayDirX < 0)
	// 		{
	// 			stepX = -1;
	// 			sideDistX = (game->view->pos.x - mapX) * deltaDistX;
	// 		}
	// 		else
	// 		{
	// 			stepX = 1;
	// 			sideDistX = (mapX + 1.0 - game->view->pos.x) * deltaDistX;
	// 		}
	// 		if (rayDirY < 0)
	// 		{
	// 			stepY = -1;
	// 			sideDistY = (game->view->pos.y - mapY) * deltaDistY;
	// 		}
	// 		else
	// 		{
	// 			stepY = 1;
	// 			sideDistY = (mapY + 1.0 - game->view->pos.y) * deltaDistY;
	// 		}

	// 		while (hit == 0)
	// 		{
	// 			if (sideDistX < sideDistY)
	// 			{
	// 				sideDistX += deltaDistX;
	// 				mapX += stepX;
	// 				side = 0;
	// 			}
	// 			else
	// 			{
	// 				sideDistY += deltaDistY;
	// 				mapY += stepY;
	// 				side = 1;
	// 			}
	// 			if (game->map->content[mapX][mapY] > 0) hit = 1;
	// 		}

	// 		if (side == 0)
	// 			perpWallDist = (mapX - game->view->pos.x + (1 - stepX) / 2) / rayDirX;
	// 		else
	// 			perpWallDist = (mapY - game->view->pos.y + (1 - stepY) / 2) / rayDirY;

	// 		int lineHeight = (int)(800 / perpWallDist);

	// 		int drawStart = -lineHeight / 2 + game->map->res_y / 2;
	// 		if(drawStart < 0) drawStart = 0;

	// 		int drawEnd = lineHeight / 2 + game->map->res_y / 2;
	// 		if(drawEnd >= game->map->res_y)drawEnd = game->map->res_y - 1;

	// 		t_rgb	color = rgb_init(200, 78, 100);
	// 		if (side == 1)
	// 			color = rgb_init(0, 200, 50);

	// 		frame_put_line(frame, vect_init(x, drawStart), lineHeight, color);
	// 	}
	// 	frame_push(frame);
	// 	frame_free(frame);
	// }