/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:22:39 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 11:29:56 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	is_digit(unsigned int i, char c)
{
	(void)i;
	if (!ft_isdigit(c) && c != ' ')
		err_exit(ERRTYPE_BADMAP);
	return (c);
}

void		map_meta_ea(t_map *map, char *line)
{
	size_t	i;
	char **strs;

	if (!(strs = ft_split(line, ' ')))
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
	char	**strs;

	if (!(strs = ft_split(line, ' ')))
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
	size_t	i;
	char	*str;
	char	**strs;

	if (!(str = ft_substr(line, 2, ft_strlen(line))))
		err_exit(ERRTYPE_NOMEM);
	if (!(strs = ft_split(str, ',')))
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 3)
		err_exit(ERRTYPE_BADMAP);
	i = 0;
	while (i < 3)
		ft_strmapi(strs[i++], &is_digit);
	map->cl_floor = rgb_init(ft_atoi(strs[0]), ft_atoi(strs[1]),
	ft_atoi(strs[2]));
	ft_splitfree(strs);
	free(str);
}

void		map_meta_c(t_map *map, char *line)
{
	size_t	i;
	char	*str;
	char	**strs;

	if (!(str = ft_substr(line, 2, ft_strlen(line))))
		err_exit(ERRTYPE_NOMEM);
	if (!(strs = ft_split(str, ',')))
		err_exit(ERRTYPE_NOMEM);
	i = 0;
	while (strs[i])
		i++;
	if (i != 3)
		err_exit(ERRTYPE_BADMAP);
	i = 0;
	while (i < 3)
		ft_strmapi(strs[i++], &is_digit);
	map->cl_ceiling = rgb_init(ft_atoi(strs[0]), ft_atoi(strs[1]),
	ft_atoi(strs[2]));
	ft_splitfree(strs);
	free(str);
}
