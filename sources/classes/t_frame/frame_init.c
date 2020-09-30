/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:57:55 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:51:31 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_frame		*frame_init(t_game *game)
{
	t_frame	*frame;

	if (!(frame = ft_calloc(1, sizeof(t_frame))))
		err_exit(ERRTYPE_NOMEM);
	frame->game = game;
	frame->img = mlx_new_image(game->display->mlx_ptr, game->map->res_x,
	game->map->res_y);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp, &frame->line_len,
	&frame->endian);
	return (frame);
}
