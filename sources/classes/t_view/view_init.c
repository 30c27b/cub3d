/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:29:12 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 13:47:10 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_view		view_init(t_map *map)
{
	t_view	view;

	(void)map;
	view.direction = vect_init(0, 0);
	view.plane = vect_init(0, 0);
	view.position = vect_init(0, 0);
	return (view);
}
