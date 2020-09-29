/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vect.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:19:04 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 12:58:27 by ancoulon         ###   ########.fr       */
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
	double	x;
	double	y;
}				t_vect;

/*
** Methods ****************************************************************** **
*/

t_vect			vect_init(double x, double y);
t_vect			vect_addv(t_vect v1, t_vect v2);
t_vect			vect_multv(t_vect v1, t_vect v2);
t_vect			vect_add(t_vect v, double n);
t_vect			vect_mult(t_vect v, double n);

#endif