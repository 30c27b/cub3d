/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:43:50 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/22 17:41:17 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double move_speed = 1; 
double rot_speed = 0.3; 

int		hook_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEYCODE_W)
	{
		game->view->pos.x += game->view->dir.x * move_speed;
		game->view->pos.y += game->view->dir.y * move_speed;
	}
	if (keycode == KEYCODE_A)
	{
	}
	if (keycode == KEYCODE_S)
	{
		game->view->pos.x -= game->view->dir.x * move_speed;
		game->view->pos.y -= game->view->dir.y * move_speed;
	}
	if (keycode == KEYCODE_D)
	{
	}
	if (keycode == KEYCODE_RIGTARROW)
	{
		double oldDirX = game->view->dir.x;
		game->view->dir.x = game->view->dir.x * cos(-rot_speed) - game->view->dir.y * sin(-rot_speed);
		game->view->dir.y = oldDirX * sin(-rot_speed) + game->view->dir.y * cos(-rot_speed);
		double oldPlaneX = game->view->fov.x;
		game->view->fov.x = game->view->fov.x * cos(-rot_speed) - game->view->fov.y * sin(-rot_speed);
		game->view->fov.y = oldPlaneX * sin(-rot_speed) + game->view->fov.y * cos(-rot_speed);
	}
	if (keycode == KEYCODE_LEFTARROW)
	{
		double oldDirX = game->view->dir.x;
		game->view->dir.x = game->view->dir.x * cos(rot_speed) - game->view->dir.y * sin(rot_speed);
		game->view->dir.y = oldDirX * sin(rot_speed) + game->view->dir.y * cos(rot_speed);
		double oldPlaneX = game->view->fov.x;
		game->view->fov.x = game->view->fov.x * cos(rot_speed) - game->view->fov.y * sin(rot_speed);
		game->view->fov.y = oldPlaneX * sin(rot_speed) + game->view->fov.y * cos(rot_speed);
	}
	return (0);
}