/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:20:15 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 15:45:39 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			hook_exit(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)keycode;
	game_free(game);
	exit(EXIT_SUCCESS);
}
