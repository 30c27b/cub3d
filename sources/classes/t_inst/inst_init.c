/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:37:18 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 12:42:10 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_inst		inst_init(t_map	map, t_win win)
{
	t_inst	instance;

	if (!(instance.mlx_ptr = mlx_init()))
		exit(EXIT_FAILURE);
	instance.map = map;
	instance.win = win;
	return (instance);
}