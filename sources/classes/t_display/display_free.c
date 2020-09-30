/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:54:30 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:48:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_free(t_display *display)
{
	mlx_destroy_window(display->mlx_ptr, display->win_ptr);
	free(display);
}
