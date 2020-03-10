/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:56:46 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/10 11:12:59 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void		mp_check_args(int ac, char **av, t_map_file *file)
{
	if (ac < 2 || ac > 3)
		err_exit(ERRTYPE_NOARG);
	if (!av[2][1])
		err_exit(ERRTYPE_BADARG);
	if (ac == 3 && ft_strcmp("--save", av[2]))
		err_exit(ERRTYPE_BADARG2);
	file->save = (ac == 3) ? TRUE : FALSE;
	file->path = av[1];
}
