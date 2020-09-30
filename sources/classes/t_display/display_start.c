/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:24:06 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:09:40 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_start(t_display display)
{
	mlx_loop(display.ptr);
}