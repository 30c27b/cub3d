/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:35:34 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/14 15:56:28 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		game_start(t_game *game)
{
	 map_print(game->map);
	mlx_loop_hook(game->display->mlx_ptr, &hook_loop, (void *)game);
	mlx_hook(game->display->win_ptr, XEVENT_KEYPRESS, 0, &hook_keypress, (void *)game);
	mlx_hook(game->display->win_ptr, XEVENT_KEYRELEASE, 0, &hook_keyrelease, (void *)game);
	mlx_hook(game->display->win_ptr, XEVENT_EXIT, 0, &hook_exit, (void *)game);
	mlx_loop(game->display->mlx_ptr);
}
