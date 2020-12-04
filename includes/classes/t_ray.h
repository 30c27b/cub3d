/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:15:34 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/04 18:26:42 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RAY_H
# define T_RAY_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_ray
{
	double	cam_x;
	t_fvect	dir;
	t_vect	map;
	t_fvect	side_dist;
	t_fvect	delta_dist;
	double	wall_dist;
	t_vect	step;
	t_bool	hit;
	int		wall_side;

}				t_ray;

/*
** Methods ****************************************************************** **
*/

t_ray*			ray_init(t_frame* frame, int w);
void			ray_free(t_ray *frame);

#endif
