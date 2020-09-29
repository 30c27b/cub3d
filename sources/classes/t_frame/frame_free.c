/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:52:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 15:54:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_free(t_frame *frame, t_game *game)
{
	mlx_destroy_image(game->mlx.ptr, frame->img);
	free(frame);
}
