/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_frame.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:22:24 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/23 17:33:42 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FRAME_H
# define T_FRAME_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_frame
{
	t_game	*game;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_frame;

// typedef struct	s_frame_ray
// {
// 	double	cam;
// 	t_fvect	dir;
// 	t_vect	map;
// 	t_fvect	side_dist;
// 	t_fvect	delta_dist;
// 	double	wall_dist;
// 	t_vect	step;
// 	t_bool	hit;
// 	int		wall_side;

// }				t_frame_ray;


/*
** Methods ****************************************************************** **
*/

t_frame			*frame_init(t_game *game);
void			frame_put_pixel(t_frame *frame, t_vect pos, t_rgb color);
void			frame_put_line(t_frame *frame, t_vect top, int len, t_rgb color);
void			frame_push(t_frame *frame);
void			frame_free(t_frame *frame);

#endif
