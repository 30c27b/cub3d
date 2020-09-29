/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvect_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:58:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 15:22:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvect		fvect_add(t_fvect v, double n)
{
	t_fvect	vect;

	vect.x = v.x + n;
	vect.y = v.y + n;
	return (vect);
}
