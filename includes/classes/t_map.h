/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:52 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/12 12:32:09 by ancoulon         ###   ########.fr       */
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
	int			res_x;
	int			res_y;
	t_texture	*tx_no;
	t_texture	*tx_so;
	t_texture	*tx_we;
	t_texture	*tx_ea;
	t_texture	*tx_s;
	t_rgb		cl_floor;
	t_rgb		cl_ceiling;
	uint64_t	height;
	uint64_t	width;
	int8_t		**content;
	t_list		*sprites;
	int			s_len;
	char		direction;
	int			pos_x;
	int			pos_y;
	t_bool		save;
}				t_map;

typedef struct	s_map_meta
{
	uint8_t		identifier;
	void		(*parser)(t_map*, char*);
}				t_map_meta;

/*
** Methods ****************************************************************** **
*/

t_map			*map_init(int ac, char **av);
void			map_process_tex(t_map *map, void *mlx_ptr);
t_bool			map_isfloor(t_map *map, t_fvect v);
void			map_free(t_map *map, void *mlx_ptr);

/*
** Private methods ********************************************************** **
*/

void			map_parse_content(t_map *map, t_list *list);
t_list			*map_parse_meta(t_map *map, t_list *list);
void			map_meta_r(t_map *map, char *line);
void			map_meta_no(t_map *map, char *line);
void			map_meta_so(t_map *map, char *line);
void			map_meta_we(t_map *map, char *line);
void			map_meta_ea(t_map *map, char *line);
void			map_meta_s(t_map *map, char *line);
void			map_meta_f(t_map *map, char *line);
void			map_meta_c(t_map *map, char *line);
void			map_enclosing(t_map *map);

#endif
