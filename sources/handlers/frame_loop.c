/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:53:56 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 16:06:49 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_loop(t_game *game)
{
	t_frame		*frame;
	static int	i = 0;

	frame = frame_init(game);
	frame_put_pixel(frame, vect_init(10, 10), rgb_init(255, 0, 0));
	i++;
	frame_push(frame, game);
	frame_free(frame, game);
}
