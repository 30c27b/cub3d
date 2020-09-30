/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:28:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 20:15:18 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		*game_init(int ac, char **av)
{
	t_game	*game;
	//int		screen_x;
	//int		screen_y;

	printf("test\n");
	if (!(game = malloc(sizeof(t_game))))
		err_exit(ERRTYPE_NOMEM);
	ft_memset(game, 0, sizeof(t_game));
		printf("test2\n");
	game->map = map_init(ac, av);
			printf("test3\n");
	//mlx_get_screen_size(game->mlx.ptr, &screen_x, &screen_y);
	//printf("%d, %d\n", screen_x, screen_y);
	// game->map->res_x = game->map->res_x < screen_x ? game->map->res_x : screen_x;
	// game->map->res_y = game->map->res_y < screen_y ? game->map->res_y : screen_y;
	game->mlx = inst_init(game->map);
	game->view = view_init(game->map);
	return (game);
}
