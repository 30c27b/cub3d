/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_get_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:11:30 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/10 17:01:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rgb		texture_get_pixel(t_texture *texture, t_vect pos)
{
	char		*pxl;
	int32_t		ref;

	
	pxl = texture->addr + (pos.y * texture->line_len + pos.x * (texture->bpp / 8));
	ref = *(int32_t *)pxl;
	return (rgb_from_int(ref));
}
