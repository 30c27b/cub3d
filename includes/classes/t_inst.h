/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_inst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:54 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 16:36:29 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INST_H
# define T_INST_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_inst
{
	void		*ptr;
	t_win		win;
	t_map		map;
}				t_inst;

/*
** Methods ****************************************************************** **
*/

t_inst			inst_init(t_map	map);
void			inst_close_win(t_inst instance);

#endif
