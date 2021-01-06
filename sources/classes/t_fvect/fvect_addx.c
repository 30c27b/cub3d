/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvect_addx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:02:50 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/06 17:57:19 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvect		fvect_addx(t_fvect v, double n)
{
	t_fvect	vect;

	vect.x = v.x + n;
	vect.y = v.y;
	return (vect);
}
