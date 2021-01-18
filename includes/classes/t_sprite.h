/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sprite.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:41:49 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/18 13:46:04 by ancoulon         ###   ########.fr       */
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
	t_fvect		pos;
}				t_sprite;

/*
** Methods ****************************************************************** **
*/

t_sprite		*sprite_init(t_fvect pos);
void			sprite_free(void *param);

#endif
