/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_frame_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/11 21:40:40 by ancoulon         ###   ########.fr       */
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
		ray_process(ray, game);

		int lineHeight = (int)(game->map->res_y / ray->wall_dist);

		int drawStart = -lineHeight / 2 + game->map->res_y / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + game->map->res_y / 2;
		if (drawEnd >= game->map->res_y)
			drawEnd = game->map->res_y - 1;

		if (ray->wall_side== 0)
			ray->wall_tex = game->map->tx_no;
		else if (ray->wall_side== 1)
			ray->wall_tex = game->map->tx_so;
		else if (ray->wall_side== 2)
			ray->wall_tex = game->map->tx_we;
		else if (ray->wall_side== 3)
			ray->wall_tex = game->map->tx_ea;
		else
			ray->wall_tex = game->map->tx_no;

		if (ray->wall_side < 2)
			ray->wall_x = game->view->pos.y + ray->wall_dist * ray->dir.y;
		else
			ray->wall_x = game->view->pos.x + ray->wall_dist * ray->dir.x;
		ray->wall_x -= floor((ray->wall_x));

		//x coordinate on the texture
		int texX = (int)(ray->wall_x * (double)TEX_WIDTH);
		if(ray->wall_side < 2 && ray->dir.x > 0)
			texX = TEX_WIDTH - texX - 1;
		if(ray->wall_side >= 2 && ray->dir.y < 0)
			texX = TEX_WIDTH - texX - 1;
		
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * TEX_HEIGHT / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - game->map->res_y / 2 + lineHeight / 2) * step;

		for(int screen_y = 0; screen_y<game->map->res_y; screen_y++)
		{
			if (screen_y < drawStart)
				frame_put_pixel(frame, vect_init(screen_x, screen_y), game->map->cl_ceiling);
			else if (screen_y >= drawStart && screen_y <= drawEnd)
			{
				int texY = (int)texPos & (TEX_HEIGHT - 1);
				texPos += step;
				t_rgb color = texture_get_pixel(ray->wall_tex, vect_init(texX, texY));
				frame_put_pixel(frame, vect_init(screen_x, screen_y), color);
			}
			else
				frame_put_pixel(frame, vect_init(screen_x, screen_y), game->map->cl_floor);
		}

		ray_free(ray);
		screen_x++;
	}

	frame_push(frame);
	frame_free(frame);
}
