/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_texture.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:20:13 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/11 14:18:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TEXTURE_H
# define T_TEXTURE_H

# include "cub3d.h"

/*
** Structure **************************************************************** **
*/

typedef struct	s_texture
{
	char		*path;
	void		*img;
	int			width;
	int			height;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_texture;

/*
** Methods ****************************************************************** **
*/

t_texture		*texture_init(char *path);
void			texture_process(t_texture *texture, void *mlx_ptr);
t_rgb			texture_get_pixel(t_texture *texture, t_vect pos);
void			texture_free(t_texture *texture, void *mlx_ptr);

#endif
