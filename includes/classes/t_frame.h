/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_frame.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:22:24 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 12:22:11 by ancoulon         ###   ########.fr       */
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
	t_game		*game;
	void		*img;
	uint32_t	*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		*z_buffer;
}				t_frame;

typedef struct	s_frame_sp
{
	t_list		*el;
	t_sprite	*s;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
	int			tex_x;
	int			y;
	int			d;
	int			tex_y;
	t_rgb		color;


}				t_frame_sp;

/*
** Methods ****************************************************************** **
*/

t_frame			*frame_init(t_game *game);
void			frame_put_pixel(t_frame *frame, t_vect pos, t_rgb color);
void			frame_render(t_frame *frame);
void			frame_push(t_frame *frame);
void			frame_save(t_frame *frame);
void			frame_free(t_frame *frame);

void 			frame_draw_sprites(t_frame *frame);

#endif
