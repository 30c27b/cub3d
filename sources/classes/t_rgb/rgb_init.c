/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:29:35 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 12:54:46 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/t_rgb.h"

t_rgb		rgb_init(t_uint8 r, t_uint8 g, t_uint8 b)
{
	t_rgb	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
