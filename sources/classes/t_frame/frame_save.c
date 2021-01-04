/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:21:46 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/20 22:00:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	bmp_header(t_frame *frame, int filesize)
{
	extern int	g_bmp_fd;
	uint8_t		header[54];

	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &filesize, 4);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_memcpy(header + 18, &frame->game->map->res_x, 4);
	ft_memcpy(header + 22, &frame->game->map->res_y, 4);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	if ((write(g_bmp_fd, header, 54)) < 54)
		err_exit(ERRTYPE_BMP);
}

void		frame_save(t_frame *frame)
{
	extern int	g_bmp_fd;
	int			pad;
	int			filesize;

	pad = (4 - (frame->game->map->res_x * 3) % 4) % 4;
	filesize = 54 + (3 * (frame->game->map->res_x + pad) * frame->game->map->res_y);
	if ((g_bmp_fd = open(SAVE_FILE, O_WRONLY | O_CREAT | O_TRUNC |
	O_APPEND)) < 0)
		err_exit(ERRTYPE_BMP);
	bmp_header(frame, filesize);
	if ((write(g_bmp_fd, frame->addr, filesize) < 0))
		err_exit(ERRTYPE_BMP);
	close(g_bmp_fd);
	g_bmp_fd = -1;
}
