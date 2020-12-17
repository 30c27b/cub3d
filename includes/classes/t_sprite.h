/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sprite.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:41:49 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/17 15:58:26 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SPRITE_H
# define T_SPRITE_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_sprite
{
	t_vect		pos;
}				t_sprite;

/*
** Methods ****************************************************************** **
*/

t_sprite		*sprite_init(t_vect pos);
void			sprite_free(t_sprite *sprite);

#endif