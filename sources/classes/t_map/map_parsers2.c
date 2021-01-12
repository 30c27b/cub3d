/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:22:39 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/12 10:38:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	is_digit(unsigned int i, char c)
{
	(void)i;
	if (!ft_isdigit(c))
		err_exit(ERRTYPE_BADMAP);
	return (c);
}

static void	check_color(char *s)
{
	char	*str;

	if (!(str = ft_strtrim(s, " ")))
		err_exit(ERRTYPE_NOMEM);
	if (!ft_strlen(str))
		err_exit(ERRTYPE_BADMAP);
	ft_strmapi(str, &is_digit);
	if (ft_strlen(str) > 3)
		err_exit(ERRTYPE_BADMAP);
	if (ft_atoi(str) < 0 || ft_atoi(str) > 255)
		err_exit(ERRTYPE_BADMAP);
	free(str);
}

void		map_meta_s(t_map *map, char *line)
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
	map->tx_s = texture_init(path);
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
	free(str);
	i = 0;
	while (strs[i])
		i++;
	if (i != 3)
		err_exit(ERRTYPE_BADMAP);
	i = 0;
	while (i < 3)
		check_color(strs[i++]);
	map->cl_floor = rgb_init(ft_atoi(strs[0]), ft_atoi(strs[1]),
	ft_atoi(strs[2]));
	ft_splitfree(strs);
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
	free(str);
	i = 0;
	while (strs[i])
		i++;
	if (i != 3)
		err_exit(ERRTYPE_BADMAP);
	i = 0;
	while (i < 3)
		check_color(strs[i++]);
	map->cl_ceiling = rgb_init(ft_atoi(strs[0]), ft_atoi(strs[1]),
	ft_atoi(strs[2]));
	ft_splitfree(strs);
}
