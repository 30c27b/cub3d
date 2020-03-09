/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:52 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 11:22:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_map
{
	t_uint64	res_x;
	t_uint64	res_y;
	void		*tx_no;
	void		*tx_so;
	void		*tx_we;
	void		*tx_ea;
	void		*tx_s;
	t_rgb		cl_f;
	t_rgb		cl_c;
	t_list		*data;
}				t_map;
