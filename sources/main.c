/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:03:11 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/24 13:29:33 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ************************************************************************** **
**                                                                            **
**                                             ______      __   _____ ____    **
**                                            / ____/_  __/ /_ |__  // __ \   **
**                                           / /   / / / / __ \ /_ </ / / /   **
**                                          / /___/ /_/ / /_/ /__/ / /_/ /    **
** Cub3D                                    \____/\__,_/_.___/____/_____/     **
** 2020 Antoine Coulon @ s19                                                  **
** ************************************************************************** **
*/

#include "cub3d.h"

int			main(int argc, char **argv)
{
	t_file	*file;
	t_map	*map;

	file = file_init(argc, argv);
	map = map_init(file);
	map_print(map);
	printf("\nmain (%lu): {%s}\n",ft_strlen(map->tx_no), map->tx_no);
	printf("pointer2: %p\n", map->tx_no);
	ft_putendl_fd(map->tx_no, 1);
	for (size_t i = 0; i < 27; i++)
	{
		printf("%d ", map->tx_no[i]);
	}
	printf("\n");
	exit(EXIT_SUCCESS);
	// (void)argc;
	// (void)argv;
	// char **strs = ft_split("  heyhey hey heyheyhey  ", ' ');
	// char *str = ft_strdup(strs[0]);
	// printf("before free: %s\n", str);
	// ft_splitfree(strs);
	// printf("after free: %s\n", str);
	// void *test = malloc(20);
	// memset(test, 48, 20);
	// printf("after alloc: %s\n", str);
}
