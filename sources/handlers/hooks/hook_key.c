/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:43:50 by ancoulon          #+#    #+#             */
/*   Updated: 2020/10/28 10:26:10 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hook_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEYCODE_W && map_floor(game->map, fvect_addx(game->view->pos, 1)))
		game->view->pos.x += 1;
	if (keycode == KEYCODE_A && map_floor(game->map, fvect_addy(game->view->pos, -1)))
		game->view->pos.y -= 1;
	if (keycode == KEYCODE_S && map_floor(game->map, fvect_addx(game->view->pos, -1)))
		game->view->pos.x -= 1;
	if (keycode == KEYCODE_W && map_floor(game->map, fvect_addy(game->view->pos, 1)))
		game->view->pos.y += 1;
	return (0);
}