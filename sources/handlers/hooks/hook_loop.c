/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:57:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/20 20:18:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	direction_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->view->keyflag & KEY_RIGTARROW)
	{
		old_dir_x = game->view->dir.x;
		game->view->dir.x = game->view->dir.x * cos(ROT_SPEED) -
		game->view->dir.y * sin(ROT_SPEED);
		game->view->dir.y = old_dir_x * sin(ROT_SPEED) + game->view->dir.y *
		cos(ROT_SPEED);
		old_plane_x = game->view->fov.x;
		game->view->fov.x = game->view->fov.x * cos(ROT_SPEED) -
		game->view->fov.y * sin(ROT_SPEED);
		game->view->fov.y = old_plane_x * sin(ROT_SPEED) + game->view->fov.y *
		cos(ROT_SPEED);
	}
}

static void	direction_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->view->keyflag & KEY_LEFTARROW)
	{
		old_dir_x = game->view->dir.x;
		game->view->dir.x = game->view->dir.x * cos(-ROT_SPEED) -
		game->view->dir.y * sin(-ROT_SPEED);
		game->view->dir.y = old_dir_x * sin(-ROT_SPEED) + game->view->dir.y
		* cos(-ROT_SPEED);
		old_plane_x = game->view->fov.x;
		game->view->fov.x = game->view->fov.x * cos(-ROT_SPEED) -
		game->view->fov.y * sin(-ROT_SPEED);
		game->view->fov.y = old_plane_x * sin(-ROT_SPEED) +
		game->view->fov.y * cos(-ROT_SPEED);
	}
}

static void	movement(t_game *game)
{
	t_fvect new_pos;

	new_pos = game->view->pos;
	if (game->view->keyflag & KEY_W)
	{
		new_pos.x += game->view->dir.x * MOVE_SPEED;
		new_pos.y += game->view->dir.y * MOVE_SPEED;
	}
	if (game->view->keyflag & KEY_A)
	{
		new_pos.x += game->view->dir.y * MOVE_SPEED;
		new_pos.y -= game->view->dir.x * MOVE_SPEED;
	}
	if (game->view->keyflag & KEY_S)
	{
		new_pos.x -= game->view->dir.x * MOVE_SPEED;
		new_pos.y -= game->view->dir.y * MOVE_SPEED;
	}
	if (game->view->keyflag & KEY_D)
	{
		new_pos.x -= game->view->dir.y * MOVE_SPEED;
		new_pos.y += game->view->dir.x * MOVE_SPEED;
	}
	if (map_isfloor(game->map, new_pos))
		game->view->pos = new_pos;
}

int			hook_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	direction_right(game);
	direction_left(game);
	movement(game);
	beta_frame_loop(game);
	return (0);
}
