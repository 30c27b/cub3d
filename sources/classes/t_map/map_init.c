/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:09:01 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 11:11:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*map_init(t_file *file)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		err_exit(ERRTYPE_NOMEM);
	ft_memset(map, 0, sizeof(t_map));
	map_parse_content(map, map_parse_meta(map, file->data));
	map_enclosing(map);
	return (map);
}
