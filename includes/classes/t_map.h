/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:52 by ancoulon          #+#    #+#             */
/*   Updated: 2020/04/25 18:22:25 by ancoulon         ###   ########.fr       */
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
	t_uint64	map_x;
	t_int32		**map;
	t_bool		save;
}				t_map;

/*
** Methods ****************************************************************** **
*/

t_map			map_init(t_file file);

#endif
