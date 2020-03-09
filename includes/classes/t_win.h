/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_win.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:49 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 12:49:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_win
{
	t_uint64	x;
	t_uint64	y;
	void		*ptr;
}				t_win;

t_win			win_init(void *mlx_ptr, t_uint64 x, t_uint64 y);