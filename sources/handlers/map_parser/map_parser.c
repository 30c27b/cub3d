/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:56:12 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/11 11:49:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void		print_map(t_list **lst)
{
	t_list	*el;

	el = *lst;
	while (el)
	{
		printf("~ |%s|\n", el->content);
		el = el->next;
	}
}

t_map		map_parser(int ac, char **av)
{
	t_map		map;
	t_map_file	file;

	mp_check_args(ac, av, &file);
	mp_read_file(&file);
	print_map(&file.data);
	map = map_init(0, 0);
	return (map);
}
