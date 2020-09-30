/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:28:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:21:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		*game_init(int ac, char **av)
{
	t_game	*game;
	int		screen_x;
	int		screen_y;

	if (!(game = malloc(sizeof(t_game))))
		err_exit(ERRTYPE_NOMEM);
	ft_memset(game, 0, sizeof(t_game));
	game->map = map_init(ac, av);
	mlx_get_screen_size(game->display.ptr, &screen_x, &screen_y);
	game->map->res_x = game->map->res_x < screen_x ? game->map->res_x : screen_x;
	game->map->res_y = game->map->res_y < screen_y ? game->map->res_y : screen_y;
	game->display = display_init(game->map);
	game->view = view_init(game->map);
	return (game);
}
