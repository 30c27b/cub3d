/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:03:11 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 14:26:57 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(void)
{
	t_inst	instance;

	instance = inst_init(map_init(500, 500));
	mlx_loop(instance.mlx_ptr);
	printf("hey\n");
}
