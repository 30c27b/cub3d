/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:03:11 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 09:54:36 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char **argv)
{
	if (argc == 2)
	{

	}
	else if (argc == 3)
	{
		if (!strcmp("--save", argv[2]))
		{
			
		}
		else
		{
			errno = EINVAL;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		errno = EINVAL;
		exit(EXIT_FAILURE);
	}
}
