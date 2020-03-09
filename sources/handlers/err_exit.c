/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:55:33 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 16:38:55 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		err_exit(char *msg)
{
	ft_putstr_fd(ERR_PREFIX, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(ERR_SUFFIX, 2);
	exit(EXIT_FAILURE);
}
