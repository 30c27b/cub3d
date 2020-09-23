/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:22:39 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/23 13:10:25 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_meta_ea(t_map *map, char *line)
{
	size_t	i;
	char **strs;

	if ((strs = ft_split(line, ' ')) == 0)
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		err_exit(ERRTYPE_BADMAP);
	map->tx_ea = ft_strdup(strs[1]);
	ft_splitfree(strs);
}

void		map_meta_s(t_map *map, char *line)
{
	size_t	i;
	char **strs;

	if ((strs = ft_split(line, ' ')) == 0)
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		err_exit(ERRTYPE_BADMAP);
	map->tx_s = ft_strdup(strs[1]);
	ft_splitfree(strs);
}

void		map_meta_f(t_map *map, char *line)
{
	(void)map;
	(void)line;
}

void		map_meta_c(t_map *map, char *line)
{
	(void)map;
	(void)line;
}