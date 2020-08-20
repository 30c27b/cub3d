/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:52 by ancoulon          #+#    #+#             */
/*   Updated: 2020/08/20 12:40:24 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_map
{
	t_uint64	res_x;
	t_uint64	res_y;
	void		*tx_no;
	void		*tx_so;
	void		*tx_we;
	void		*tx_ea;
	void		*tx_s;
	t_rgb		cl_floor;
	t_rgb		cl_ceiling;
	t_uint64	map_x;
	t_uint64	map_y;
	t_int32		**map;
	t_bool		save;
}				t_map;

// typedef enum	e_map_el
// {
// 	FLAG_R = BIT_0,
// 	FLAG_NO = BIT_1,
// 	FLAG_SO = BIT_2,
// 	FLAG_WE = BIT_3,
// 	FLAG_EA = BIT_4,
// 	FLAG_S = BIT_5,
// 	FLAG_F = BIT_6,
// 	FLAG_C = BIT_7
// }				t_map_el;

/*
** Methods ****************************************************************** **
*/

t_map			map_init(t_file file);

#endif
