/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:21:46 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/04 16:37:32 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	bmp_header(t_frame *frame, int imgsize)
{
	extern int	g_bmp_fd;
	uint8_t		header[54];
	int			filesize;

	filesize = imgsize + 54;
	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &imgsize, 4);
	ft_memcpy(header + 10, &(int){54}, 4);
	ft_memcpy(header + 14, &(int){40}, 4);
	ft_memcpy(header + 18, &frame->game->map->res_x, 4);
	ft_memcpy(header + 22, &frame->game->map->res_y, 4);
	ft_memcpy(header + 26, &(int){1}, 2);
	ft_memcpy(header + 28, &(int){32}, 2);
	ft_memcpy(header + 34, &filesize, 4);
	if ((write(g_bmp_fd, header, 54)) < 54)
		err_exit(ERRTYPE_BMP);
}

void		frame_save(t_frame *frame)
{
	extern int	g_bmp_fd;
	int			imgsize;

	imgsize = frame->game->map->res_y * frame->game->map->res_x * 4;
	if ((g_bmp_fd = open(SAVE_FILE, O_WRONLY | O_TRUNC | O_APPEND, S_IRWXU)) < 0)
		err_exit(ERRTYPE_BMP);
	bmp_header(frame, imgsize);
	if ((write(g_bmp_fd, frame->addr, imgsize) < 0))
		err_exit(ERRTYPE_BMP);
	close(g_bmp_fd);
	g_bmp_fd = -1;
}
