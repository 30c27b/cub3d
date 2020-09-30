/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_fromf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:06:48 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 12:50:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect			vect_fromf(t_fvect fvect)
{
	t_vect	vect;

	vect.x = (t_int64)fvect.x;
	vect.y = (t_int64)fvect.y;
	return (vect);
}
