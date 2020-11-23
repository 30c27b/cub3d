/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:35:34 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/19 17:20:16 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		game_start(t_game *game)
{
	mlx_loop_hook(game->display->mlx_ptr, &hook_loop, (void *)game);
	mlx_key_hook(game->display->win_ptr, &hook_key, (void *)game);
	mlx_loop(game->display->mlx_ptr);
}
