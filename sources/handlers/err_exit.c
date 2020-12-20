/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:55:33 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/19 11:25:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			g_file_fd = -1;
int			g_bmp_fd = -1;

void		err_exit(char *msg)
{
	extern int	g_file_fd;

	if (g_file_fd > 0)
		close(g_file_fd);
	if (g_bmp_fd > 0)
		close(g_bmp_fd);
	ft_putstr_fd(ERR_PREFIX, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(ERR_SUFFIX, 2);
	exit(EXIT_FAILURE);
}
