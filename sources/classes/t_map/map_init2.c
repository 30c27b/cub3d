/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:15:41 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/21 15:18:17 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void inc_flag(t_uint8 el_flag, t_uint8 bitflag)
{
	if (el_flag & bitflag)
		err_exit(ERRTYPE_BADMAP);
	el_flag |= bitflag;
}

static void	parse_type(char *line, t_map *map, t_uint8 el_flag)
{
	if (!ft_strncmp(line, "R", 1))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "NO", 2))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "SO", 2))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "WE", 2))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "EA", 2))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "S", 1))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "F", 1))
		inc_flag(el_flag, BIT_0);
	else if (!ft_strncmp(line, "C", 1))
		inc_flag(el_flag, BIT_0);
	else
		err_exit(ERRTYPE_BADMAP);
}

void 		map_init_parse_el(char *line, t_map *map, t_uint8 el_flag[8])
{

}
