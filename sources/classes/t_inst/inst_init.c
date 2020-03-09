/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:37:18 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 12:55:53 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/t_inst.h"

t_inst		inst_init(t_map	map)
{
	t_inst	instance;

	instance.map = map;
	if (!(instance.mlx_ptr = mlx_init()))
		exit(EXIT_FAILURE);
	instance.win = win_init(instance.mlx_ptr, map.res_x, map.res_y);
	return (instance);
}
