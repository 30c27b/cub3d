/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:14:11 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 15:14:39 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FVECT_H
# define T_FVECT_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_fvect
{
	double	x;
	double	y;
}				t_fvect;

/*
** Methods ****************************************************************** **
*/

t_vect			fvect_init(double x, double y);
t_vect			fvect_addv(t_fvect v1, t_fvect v2);
t_vect			fvect_multv(t_fvect v1, t_fvect v2);
t_vect			fvect_add(t_fvect v, double n);
t_vect			fvect_mult(t_fvect v, double n);

#endif
