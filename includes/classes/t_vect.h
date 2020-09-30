/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vect.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:19:04 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 12:46:24 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VECT_H
# define T_VECT_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_vect
{
	t_int64		x;
	t_int64		y;
}				t_vect;

/*
** Methods ****************************************************************** **
*/

t_vect			vect_init(t_int64 x, t_int64 y);
t_vect			vect_addv(t_vect v1, t_vect v2);
t_vect			vect_multv(t_vect v1, t_vect v2);
t_vect			vect_add(t_vect v, t_int64 n);
t_vect			vect_mult(t_vect v, t_int64 n);
t_vect			vect_fromf(t_fvect fvect);

#endif
