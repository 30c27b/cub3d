/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_put_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:10:00 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:16:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_put_pixel(t_frame *frame, t_vect pos, t_rgb color)
{
	char	*pxl;

	pxl = frame->addr + (pos.y * frame->line_len + pos.x * (frame->bpp / 8));
	*(t_uint32 *)pxl = rgb_to_int(color);
}
