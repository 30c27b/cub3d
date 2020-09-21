/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:15:41 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/21 17:22:40 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_type(char *line, t_map *map, t_uint8 el_flag)
{
	if (!ft_strncmp(line, "R", 1))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "NO", 2))
		inc_flag(el_flag, BIT_1);
	else if (!ft_strncmp(line, "SO", 2))
		inc_flag(el_flag, BIT_2);
	else if (!ft_strncmp(line, "WE", 2))
		inc_flag(el_flag, BIT_3);
	else if (!ft_strncmp(line, "EA", 2))
		inc_flag(el_flag, BIT_4);
	else if (!ft_strncmp(line, "S", 1))
		inc_flag(el_flag, BIT_5);
	else if (!ft_strncmp(line, "F", 1))
		inc_flag(el_flag, BIT_6);
	else if (!ft_strncmp(line, "C", 1))
		inc_flag(el_flag, BIT_7);
	else
		err_exit(ERRTYPE_BADMAP);
}


static void redirect_els(t_map *map, char *line, t_uint8 el_flag, t_uint8 bitflag)
{
	if (el_flag & bitflag)
		err_exit(ERRTYPE_BADMAP);
	el_flag |= bitflag;
	if (bitflag == BIT_0)
		map_id_r(map, line);
	else if (bitflag == BIT_1)
		map_id_no(map, line);
	else if (bitflag == BIT_2)
		map_id_so(map, line);
	else if (bitflag == BIT_3)
		map_id_we(map, line);
	else if (bitflag == BIT_4)
		map_id_ea(map, line);
	else if (bitflag == BIT_5)
		map_id_s(map, line);
	else if (bitflag == BIT_6)
		map_id_f(map, line);
	else if (bitflag == BIT_7)
		map_id_c(map, line);
	
}


void 		map_init_parse_els(char *line, t_map *map, t_uint8 el_flag)
{

}
