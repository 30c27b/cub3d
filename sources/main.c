/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:03:11 by ancoulon          #+#    #+#             */
/*   Updated: 2020/04/25 14:55:43 by ancoulon         ###   ########.fr       */
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
	t_file	file;

	file = file_init(argc, argv);
	file_print(file);
	file_free(file);
	exit(EXIT_SUCCESS);
}
