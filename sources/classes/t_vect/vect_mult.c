/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:59:26 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 12:59:41 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect		vect_mult(t_vect v, double n)
{
	t_vect	vect;

	vect.x = v.x * n;
	vect.y = v.y * n;
	return (vect);
}
