/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_put_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:20:39 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/04 18:34:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_put_line(t_frame *frame, t_vect top, int len, t_rgb color)
{
	int	i;

	i = 0;
	while (i < len)
	{
		frame_put_pixel(frame, top, color);
		top.y += 1;
		i++;
	}
}
