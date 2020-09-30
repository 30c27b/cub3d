/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:53:56 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 20:14:42 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_loop(t_game *game)
{
	t_frame		*frame;

	frame = frame_init(game);
	frame_put_pixel(frame, vect_init(10, 10), rgb_init(255, 0, 0));
	frame_put_line(frame, vect_init(20, 30), 500, rgb_init(255, 255, 255));
	frame_push(frame);
	frame_free(frame);
}
