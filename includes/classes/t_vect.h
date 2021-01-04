/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vect.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:19:04 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/25 17:19:38 by ancoulon         ###   ########.fr       */
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
	int64_t		x;
	int64_t		y;
}				t_vect;

/*
** Methods ****************************************************************** **
*/

t_vect			vect_init(int64_t x, int64_t y);
t_vect			vect_addv(t_vect v1, t_vect v2);
t_vect			vect_multv(t_vect v1, t_vect v2);
t_vect			vect_add(t_vect v, int64_t n);
t_vect			vect_mult(t_vect v, int64_t n);
t_vect			vect_fromf(t_fvect fvect);

#endif
