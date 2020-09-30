/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:25:39 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:07:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_H
# define T_GAME_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_game
{
	t_map		*map;
	t_display	display;
	t_view		view;
}				t_game;

/*
** Methods ****************************************************************** **
*/

t_game		*game_init(int ac, char **av);
void		game_start(t_game *game);

#endif
