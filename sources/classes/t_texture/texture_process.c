/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:38:26 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/09 18:17:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		texture_process(t_texture *texture, void *mlx_ptr)
{
	if (!(texture->img = mlx_xpm_file_to_image(mlx_ptr, texture->path,
	&texture->width, &texture->height)))
		err_exit(ERRTYPE_BADTEX);
	if (texture->width != 64 || texture->height != 64)
		err_exit(ERRTYPE_BADTEX);
	if (!(texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_len,
	&texture->endian)))
	err_exit(ERRTYPE_MLX);
}
