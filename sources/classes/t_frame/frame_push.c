/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:00:27 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 16:13:45 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_push(t_frame *frame)
{
	mlx_put_image_to_window(frame->game->mlx.ptr, frame->game->mlx.win.ptr,
	frame->img, 0, 0);
}
