/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:36:29 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/12 12:32:32 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		game_free(t_game *game)
{
	map_free(game->map, game->display->mlx_ptr);
	display_free(game->display);
	view_free(game->view);
	free(game);
}
