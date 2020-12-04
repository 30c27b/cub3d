/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_view.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:27:15 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/23 17:45:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VIEW_H
# define T_VIEW_H

# include "cub3d.h"

/*
** Defines ****************************************************************** **
*/

# define KEY_ESC BIT_0
# define KEY_RIGTARROW BIT_1
# define KEY_LEFTARROW BIT_2
# define KEY_W BIT_3
# define KEY_A BIT_4
# define KEY_S BIT_5
# define KEY_D BIT_6

/*
** Structure **************************************************************** **
*/

typedef struct	s_view
{
	t_fvect	pos;
	t_fvect	dir;
	t_fvect	fov;
	uint8_t	keyflag;
}				t_view;

/*
** Methods ****************************************************************** **
*/

t_view			*view_init(t_map *map);
void			view_free(t_view *view);

#endif
