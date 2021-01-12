/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:24:38 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/12 19:52:58 by ancoulon         ###   ########.fr       */
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
	i = 1;
	while (i < 3)
		free(ft_strmapi(strs[i++], &parsing_is_digit));
	map->res_x = ft_atoi(strs[1]);
	map->res_y = ft_atoi(strs[2]);
	if (ft_strlen(strs[1]) > 6)
		map->res_x = INT32_MAX;
	if (ft_strlen(strs[2]) > 6)
		map->res_y = INT32_MAX;
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

void		map_meta_ea(t_map *map, char *line)
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
	map->tx_ea = texture_init(path);
	ft_splitfree(strs);
}
