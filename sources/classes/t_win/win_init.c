/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:44:49 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 12:55:41 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/t_win.h"

t_win		win_init(void *mlx_ptr, t_uint64 x, t_uint64 y)
{
	t_win	win;

	win.x = x;
	win.y = y;
	if (!(win.ptr = mlx_new_window(mlx_ptr, x, y, C3D_TITLE)))
		exit(EXIT_FAILURE);
}