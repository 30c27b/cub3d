/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_addv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:55:31 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 13:07:57 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect		vect_addv(t_vect v1, t_vect v2)
{
	t_vect	vect;

	vect.x = v1.x + v2.x;
	vect.y = v1.y + v2.y;
	return (vect);
}
