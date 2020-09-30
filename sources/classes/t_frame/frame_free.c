/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:52:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:50:19 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_free(t_frame *frame)
{
	mlx_destroy_image(frame->game->display->mlx_ptr, frame->img);
	free(frame);
}
