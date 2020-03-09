/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_inst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:54 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 13:34:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INST_H
# define T_INST_H

# include "cub3d.h"

typedef struct	s_inst
{
	void		*mlx_ptr;
	t_win		win;
	t_map		map;
}				t_inst;

t_inst			inst_init(t_map	map);
void			inst_close_win(t_inst instance);

#endif
