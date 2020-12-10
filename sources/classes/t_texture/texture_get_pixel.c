/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_get_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:11:30 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/09 19:17:06 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rgb		texture_get_pixel(t_texture *texture, t_vect pos)
{
	char	*pxl;

	pxl = texture->addr + (pos.y * texture->line_len + pos.x * (texture->bpp / 8));
	return (rgb_from_int((t_uint32)pxl));
}
