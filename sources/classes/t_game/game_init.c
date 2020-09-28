/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:28:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 14:35:00 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		*game_init(int ac, char **av)
{
	t_game	*game;

	if (!(game = malloc(sizeof(t_game))))
		err_exit(ERRTYPE_NOMEM);
	ft_memset(game, 0, sizeof(t_game));
	game->map = map_init(ac, av);
	game->mlx = inst_init(game->map);
	game->view = view_init(game->map);
	return (game);
}
