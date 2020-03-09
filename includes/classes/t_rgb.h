/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rgb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:51 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 12:28:53 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_rgb
{
	t_uint8		r;
	t_uint8		g;
	t_uint8		b;
}				t_rgb;

t_rgb			rgb_init(t_uint8 r, t_uint8 g, t_uint8 b);
t_int32			rgb_toint(t_rgb color);
