/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_win.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:49 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 13:34:24 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WIN_H
# define T_WIN_H

# include "cub3d.h"

typedef struct	s_win
{
	t_uint64	x;
	t_uint64	y;
	void		*ptr;
}				t_win;

t_win			win_init(void *mlx_ptr, t_uint64 x, t_uint64 y);

#endif
