/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_frame.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:22:24 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 16:28:14 by ancoulon         ###   ########.fr       */
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
	int	endian;
}				t_frame;

/*
** Methods ****************************************************************** **
*/

t_frame			*frame_init(t_game *game);
void			frame_put_pixel(t_frame *frame, t_vect pos, t_rgb color);
void			frame_free(t_frame *frame);
void			frame_push(t_frame *frame);
void			frame_put_line(t_frame *frame, t_vect top, int len, t_rgb color);

#endif
