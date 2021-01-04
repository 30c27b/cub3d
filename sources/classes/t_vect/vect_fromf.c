/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_fromf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:06:48 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/25 17:23:32 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect			vect_fromf(t_fvect fvect)
{
	t_vect	vect;

	vect.x = (int64_t)fvect.x;
	vect.y = (int64_t)fvect.y;
	return (vect);
}
