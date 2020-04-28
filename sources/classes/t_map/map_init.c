/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:09:01 by ancoulon          #+#    #+#             */
/*   Updated: 2020/04/25 18:20:42 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse(t_file file, t_map *map)
{
	t_list	*line;
	t_int32	lines;

	line = file.data;
	lines = 0;
	while (line)
	{
		if ((char *)line->content && ((char *)line->content)[0])
		{
			
			lines++;
		}
	}
}

t_map		map_init(t_file file)
{
	t_map	map;

	map.res_x = WIN_MAX_W;
	map.res_y = WIN_MAX_H;
	map.save = file.save;
	parse(file, &map);
	return (map);
}
