/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_view.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:27:15 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:55:45 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VIEW_H
# define T_VIEW_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_view
{
	t_fvect	position;
	t_fvect	direction;
	t_fvect	fov;
}				t_view;

/*
** Methods ****************************************************************** **
*/

t_view			*view_init(t_map *map);
void			view_free(t_view *view);

#endif
