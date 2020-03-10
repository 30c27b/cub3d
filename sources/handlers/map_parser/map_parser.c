/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:56:12 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/10 11:13:33 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		map_parser(int ac, char **av)
{
	t_map		map;
	t_map_file	file;

	mp_check_args(ac, av, &file);
	mp_read_file(&file);
	return (map);
}
