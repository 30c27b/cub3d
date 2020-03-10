/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:48:16 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/10 11:18:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "cub3d.h"

typedef struct	s_map_file
{
	t_bool	save;
	char	*path;
	t_int32	fd;
	t_list	**file;
}				t_map_file;


t_map			map_parser(int ac, char **av);

void			mp_check_args(int ac, char **av, t_map *map);
void			mp_read_file(t_map_file *file);

#endif