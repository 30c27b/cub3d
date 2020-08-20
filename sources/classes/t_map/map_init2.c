/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:15:41 by ancoulon          #+#    #+#             */
/*   Updated: 2020/08/20 12:56:52 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_type(char *line, t_map *map, t_uint8 el_flag[8])
{
	if (!ft_strncmp(line, "R", 1))
		el_flag[0] += 1;
	else if (!ft_strncmp(line, "NO", 2))
		el_flag[0] += 1;
	else if (!ft_strncmp(line, "SO", 2))
		el_flag[0] += 1;
	else if (!ft_strncmp(line, "WE", 2))
		el_flag[0] += 1;
	else if (!ft_strncmp(line, "EA", 2))
		el_flag[0] += 1;
	else if (!ft_strncmp(line, "S", 1))
		el_flag[0] += 1;
	else if (!ft_strncmp(line, "F", 1))
		el_flag[0] += 1;
	else if (!ft_strncmp(line, "C", 1))
		el_flag[0] += 1;
}

void 		map_init_parse_el(char *line, t_map *map, t_uint8 el_flag[8])
{

}
