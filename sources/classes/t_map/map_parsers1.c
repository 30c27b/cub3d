/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:24:38 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/09 17:51:55 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_meta_r(t_map *map, char *line)
{
	size_t	i;
	char	**strs;

	if (!(strs = ft_split(line, ' ')))
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 3)
		err_exit(ERRTYPE_BADMAP);
	if ((map->res_x = ft_atoi(strs[1])) <= 0)
		err_exit(ERRTYPE_BADMAP);
	if ((map->res_y = ft_atoi(strs[2])) <= 0)
		err_exit(ERRTYPE_BADMAP);
	ft_splitfree(strs);
}

void		map_meta_no(t_map *map, char *line)
{
	size_t	i;
	char	*path;
	char	**strs;

	if (!(strs = ft_split(line, ' ')))
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		err_exit(ERRTYPE_BADMAP);
	
	if (!(path = ft_strdup(strs[1])))
		err_exit(ERRTYPE_NOMEM);
	map->tx_no = texture_init(path);
	ft_splitfree(strs);
}

void		map_meta_so(t_map *map, char *line)
{
	size_t	i;
	char	*path;
	char	**strs;

	if (!(strs = ft_split(line, ' ')))
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		err_exit(ERRTYPE_BADMAP);
	if (!(path = ft_strdup(strs[1])))
		err_exit(ERRTYPE_NOMEM);
	map->tx_so = texture_init(path);
	ft_splitfree(strs);
}

void		map_meta_we(t_map *map, char *line)
{
	size_t	i;
	char	*path;
	char	**strs;

	if (!(strs = ft_split(line, ' ')))
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		err_exit(ERRTYPE_BADMAP);
	if (!(path = ft_strdup(strs[1])))
		err_exit(ERRTYPE_NOMEM);
	map->tx_we = texture_init(path);
	ft_splitfree(strs);
}
