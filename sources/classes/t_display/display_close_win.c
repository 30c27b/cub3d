/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_close_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:54:30 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:08:53 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_close_win(t_display display)
{
	if (display.win.ptr)
		mlx_destroy_window(display.ptr, display.win.ptr);
	display.win.ptr = NULL;
}
