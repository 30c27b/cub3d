/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_frame_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/10 18:29:13 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void beta_frame_loop(t_game *game)
{
	int screen_x;
	t_frame *frame;
	t_ray	*ray;

	screen_x = 0;
	frame = frame_init(game);

	while (screen_x < game->map->res_x)
	{
		ray = ray_init(frame, screen_x);
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
				ray->wall_side = ray->dir.x < 0? 0: 1;
			}
			else
			{
				ray->side_dist.y += ray->delta_dist.y;
				ray->map.y += ray->step.y;
				ray->wall_side = ray->dir.y < 0? 2: 3;
			}
			if (game->map->content[ray->map.x][ray->map.y] > 0)
				ray->hit = 1;
		}
		if (ray->wall_side < 2)
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

		t_texture	*wall_tex;

		switch (ray->wall_side) {
			case 0:
				wall_tex = game->map->tx_no;
				break;
			case 1:
				wall_tex = game->map->tx_so;
				break;
			case 2:
				wall_tex = game->map->tx_we;
				break;
			case 3:
				wall_tex = game->map->tx_ea;
				break;
			default:
				wall_tex = game->map->tx_s;
		}

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (ray->wall_side < 2)
			wallX = game->view->pos.y + ray->wall_dist * ray->dir.y;
		else
			wallX = game->view->pos.x + ray->wall_dist * ray->dir.x;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)TEX_WIDTH);
		if(ray->wall_side < 2 && ray->dir.x > 0)
			texX = TEX_WIDTH - texX - 1;
		if(ray->wall_side >= 2 && ray->dir.y < 0)
			texX = TEX_WIDTH - texX - 1;
		
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * TEX_HEIGHT / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - game->map->res_y / 2 + lineHeight / 2) * step;

		for(int y = drawStart; y<drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (TEX_HEIGHT - 1);
			texPos += step;
			t_rgb color = texture_get_pixel(wall_tex, vect_init(texX, texY));
			frame_put_pixel(frame, vect_init(screen_x, y), color);
		}

		ray_free(ray);
		screen_x++;
	}

	frame_push(frame);
	frame_free(frame);
}
