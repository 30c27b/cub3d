/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:00:27 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 16:02:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_push(t_frame *frame, t_game *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win.ptr, frame->img, 0, 0);
}
