/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:28:29 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 11:43:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		*game_init(int ac, char **av)
{
	t_game	*game;

	if (!(game = ft_calloc(1, sizeof(t_game))))
		err_exit(ERRTYPE_NOMEM);
	game->map = map_init(ac, av);
	game->display = display_init(game->map);
	game->view = view_init(game->map);
	map_process_tex(game->map, game->display->mlx_ptr);
	return (game);
}
