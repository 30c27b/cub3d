/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:09:01 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 10:52:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*map_init(int ac, char **av)
{
	t_file	*file;
	t_map	*map;

	if (!(map = ft_calloc(1, sizeof(t_map))))
		err_exit(ERRTYPE_NOMEM);
	file = file_init(ac, av);
	map_parse_content(map, map_parse_meta(map, file->data));
	map_enclosing(map);
	map->save = file->save;
	file_free(file);
	return (map);
}
