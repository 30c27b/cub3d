/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rgb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:51 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/10 16:38:35 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RGB_H
# define T_RGB_H

# include "cub3d.h"

/*
** Constants **************************************************************** **
*/

# define RGB_R 0x00FF0000
# define RBG_G 0x0000FF00
# define RBG_B 0x000000FF

/*
** Structure **************************************************************** **
*/

typedef struct	s_rgb
{
	t_uint8		r;
	t_uint8		g;
	t_uint8		b;
}				t_rgb;

/*
** Methods ****************************************************************** **
*/

t_rgb			rgb_init(t_uint8 r, t_uint8 g, t_uint8 b);
t_uint32		rgb_to_int(t_rgb color);
t_rgb			rgb_from_int(t_uint32 ref);
void			rgb_print(t_rgb color);

#endif
