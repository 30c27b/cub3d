/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_display.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:54 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:48:16 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DISPLAY_H
# define T_DISPLAY_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_display
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_display;

/*
** Methods ****************************************************************** **
*/

t_display		*display_init(t_map *map);
void			display_free(t_display *display);

#endif
