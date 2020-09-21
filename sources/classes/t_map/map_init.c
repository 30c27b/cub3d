/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:09:01 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/21 15:18:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse(t_file file, t_map *map)
{
	t_list	*line;
	t_int32	lines;
	char	*content;
	t_uint8 el_flag;

	line = file.data;
	lines = 0;
	el_flag = 0b00000000;
	// while (line && line->content)
	// {
	// 	content = (char *)line->content;
	// 	if (!content[0])
	// 	{

	// 	}
	// 	line = line->next;
	// }
}

t_map		map_init(t_file file)
{
	t_map	map;

	map.res_x = WIN_MAX_W;
	map.res_y = WIN_MAX_H;
	map.save = file.save;
	parse(file, &map);
	file_free(file);
	return (map);
}
