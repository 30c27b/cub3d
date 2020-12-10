/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:29:34 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/09 16:33:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture		*texture_init(char *path)
{
	t_texture	*texture;

	if (!(texture = ft_calloc(1, sizeof(t_texture))))
		err_exit(ERRTYPE_NOMEM);
	texture->path = path;
	return (texture);
}
