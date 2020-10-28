/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvect_addy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:03:15 by ancoulon          #+#    #+#             */
/*   Updated: 2020/10/28 10:45:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvect		fvect_addy(t_fvect v, double n)
{
	t_fvect	vect;

	vect.x = v.x;
	vect.y = v.y + n;
	return (vect);
}