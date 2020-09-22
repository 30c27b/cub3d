/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:43:54 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/22 14:14:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_print(t_map map)
{
	printf("res: %lu x %lu\n", map.res_x, map.res_y);
	printf("tx NO: [%s]\n", map.tx_no);
	printf("tx SO: [%s]\n", map.tx_so);
	printf("tx WE: [%s]\n", map.tx_we);
	printf("tx EA: [%s]\n", map.tx_ea);
	printf("tx S: [%s]\n", map.tx_s);
}
