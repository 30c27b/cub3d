/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:11:28 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 16:39:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_render(t_frame *frame)
{
	int		screen_x;
	t_game	*game;
	t_ray	*ray;

	screen_x = 0;
	game = frame->game;
	while (screen_x < game->map->res_x)
	{
		ray = ray_init(frame, screen_x);
		ray_dda(ray, game);
		ray_draw(ray, frame, game);
		screen_x++;
		ray_free(ray);
	}
	frame_draw_sprites(frame);
}
