/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:57:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/14 17:27:03 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			hook_loop(void *param)
{
	t_game	*game;
	t_fvect new_pos;

	game = (t_game *)param;
	new_pos = game->view->pos;

	if (game->view->keyflag & KEY_RIGTARROW)
	{
		double oldDirX = game->view->dir.x;
		game->view->dir.x = game->view->dir.x * cos(-ROT_SPEED) - game->view->dir.y * sin(-ROT_SPEED);
		game->view->dir.y = oldDirX * sin(-ROT_SPEED) + game->view->dir.y * cos(-ROT_SPEED);
		double oldPlaneX = game->view->fov.x;
		game->view->fov.x = game->view->fov.x * cos(-ROT_SPEED) - game->view->fov.y * sin(-ROT_SPEED);
		game->view->fov.y = oldPlaneX * sin(-ROT_SPEED) + game->view->fov.y * cos(-ROT_SPEED);
	}
	if (game->view->keyflag & KEY_LEFTARROW)
	{
		double oldDirX = game->view->dir.x;
		game->view->dir.x = game->view->dir.x * cos(ROT_SPEED) - game->view->dir.y * sin(ROT_SPEED);
		game->view->dir.y = oldDirX * sin(ROT_SPEED) + game->view->dir.y * cos(ROT_SPEED);
		double oldPlaneX = game->view->fov.x;
		game->view->fov.x = game->view->fov.x * cos(ROT_SPEED) - game->view->fov.y * sin(ROT_SPEED);
		game->view->fov.y = oldPlaneX * sin(ROT_SPEED) + game->view->fov.y * cos(ROT_SPEED);
	}


	if (game->view->keyflag & KEY_W)
	{
		new_pos.x += game->view->dir.x * MOVE_SPEED;
		new_pos.y += game->view->dir.y * MOVE_SPEED;
	}
	if (game->view->keyflag & KEY_A)
	{
		new_pos.x -= game->view->dir.y * MOVE_SPEED;
		new_pos.y += game->view->dir.x * MOVE_SPEED;
	}
	if (game->view->keyflag & KEY_S)
	{
		new_pos.x -= game->view->dir.x * MOVE_SPEED;
		new_pos.y -= game->view->dir.y * MOVE_SPEED;
	}
	if (game->view->keyflag & KEY_D)
	{
		new_pos.x += game->view->dir.y * MOVE_SPEED;
		new_pos.y -= game->view->dir.x * MOVE_SPEED;
	}
	printf("newpos: (%f, %f) / isfloor: %d / %hhd\n", new_pos.x, new_pos.y, map_isfloor(game->map, new_pos), game->map->content[29][36]);
	if (map_isfloor(game->map, new_pos))
		game->view->pos = new_pos;
	
	beta_frame_loop(game);
	return (0);
}
