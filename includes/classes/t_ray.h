/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:15:34 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 16:38:04 by ancoulon         ###   ########.fr       */
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
	int			screen_x;
	double		cam_x;
	t_fvect		dir;
	t_vect		map;
	t_fvect		side_dist;
	t_fvect		delta_dist;
	double		wall_dist;
	t_vect		step;
	t_bool		hit;
	int			wall_side;
	t_texture	*wall_tex;
	double		wall_x;
	int			line_h;
	int			draw_s;
	int			draw_e;
	int			tex_x;
	double		tx_step;
	double		tex_pos;
	int			screen_y;
	int			tex_y;
}				t_ray;

/*
** Methods ****************************************************************** **
*/

t_ray			*ray_init(t_frame *frame, int screen_x);
void			ray_dda(t_ray *ray, t_game *game);
void			ray_draw(t_ray *ray, t_frame *frame, t_game *game);
void			ray_free(t_ray *frame);

#endif
