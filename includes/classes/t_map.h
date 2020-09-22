/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:52 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/22 12:45:44 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_map
{
	t_uint64	res_x;
	t_uint64	res_y;
	void		*tx_no;
	void		*tx_so;
	void		*tx_we;
	void		*tx_ea;
	void		*tx_s;
	t_rgb		cl_floor;
	t_rgb		cl_ceiling;
	t_uint64	map_x;
	t_uint64	map_y;
	t_int32		**map;
	t_bool		save;
}				t_map;

typedef struct	s_map_meta
{
	t_uint8		identifier;
	void		(*parser)(t_map*, char*);
}				t_map_meta;

/*
** Methods ****************************************************************** **
*/

t_map		map_init(t_file file);

int			map_parse_meta(t_map * map, char *line);

void		map_meta_r(t_map *map, char *line);
void		map_meta_no(t_map *map, char *line);
void		map_meta_so(t_map *map, char *line);
void		map_meta_we(t_map *map, char *line);
void		map_meta_ea(t_map *map, char *line);
void		map_meta_s(t_map *map, char *line);
void		map_meta_f(t_map *map, char *line);
void		map_meta_c(t_map *map, char *line);

#endif
