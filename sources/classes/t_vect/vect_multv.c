/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_multv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:57:15 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 12:59:08 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect		vect_multv(t_vect v1, t_vect v2)
{
	t_vect	vect;

	vect.x = v1.x * v2.x;
	vect.y = v1.y * v2.y;
	return (vect);
}
