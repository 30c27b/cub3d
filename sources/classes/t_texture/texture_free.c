/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:36:05 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/11 14:18:09 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		texture_free(t_texture *texture, void *mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, texture->img);
	free(texture->path);
	free(texture);
}
