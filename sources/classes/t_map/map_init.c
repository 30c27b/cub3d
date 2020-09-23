/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:09:01 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/23 13:53:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_list	*parse_meta(t_map *map, t_list *list)
{
	t_uint8	flag;
	t_list	*el;

	flag = 0b00000000;
	el = list;
	while (el && el->content)
	{
		if (ft_isdigit(((char *)el->content)[0]) || ((char *)el->content)[0] == ' ')
			return (el);
		else if (((char *)el->content)[0] != '\0')
			map_parse_meta(map, (char *)el->content, &flag);
		el = el->next;
	}
	err_exit(ERRTYPE_BADMAP);
	exit(EXIT_FAILURE);
}

static void		map_size(t_map *map, t_list *list)
{
	t_list	*el;
	size_t	len;

	el = list;
	map->height = 0;
	map->width = 0;
	while (el && el->content && ((char *)el->content)[0] != '\0')
	{
		map->height++;
		len = ft_strlen((char *)el->content);
		if (len > map->width)
			map->width = len;
		el = el->next;
	}
}

static void		parse_map_line(t_map *map, char *line, size_t index)
{
	size_t	i;
	size_t	len;
	int		pos;

	i = 0;
	pos = 0;
	len = ft_strlen(line);
	if (!(map->content[index] = malloc(map->width)))
		err_exit(ERRTYPE_NOMEM);
	ft_memset(map->content[index], -1, map->width);
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '2')
			map->content[index][i] = line[i] - 48;
		else if (line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W')
		{
			if (pos++)
				err_exit(ERRTYPE_BADMAP);
			map->content[index][i] = 3;
			map->direction = line[i];
		}
		else if (line[i] != ' ')
			err_exit(ERRTYPE_BADMAP);
		i++;
	}
}

static void 	parse_map(t_map *map, t_list *list)
{
	t_list	*el;
	int		end;
	size_t	i;

	map_size(map, list);
	if (!(map->content = (t_int8 **)malloc(map->height)))
		err_exit(ERRTYPE_NOMEM);
	el = list;
	end = 0;
	i = 0;
	map->direction = '\0';
	while (el && el->content)
	{
		if (((char *)el->content)[0] == '\0')
			break;
		parse_map_line(map, (char *)el->content, i);
		el = el->next;
		i++;
	}
	if (map->direction == '\0')
		err_exit(ERRTYPE_BADMAP);
}

t_map		*map_init(t_file *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	map->save = file->save;
	parse_map(map, parse_meta(map, file->data));
	printf("\ninit: {%s}\n", map->tx_no);
	return (map);
}
