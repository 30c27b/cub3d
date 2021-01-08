/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:21:46 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/08 17:15:53 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	bmp_data(t_frame *frame)
{
	extern int	g_bmp_fd;
	int			i;
	int			j;
	uint32_t	pxl;


	i = frame->game->map->res_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < frame->game->map->res_x)
		{
			pxl = *(frame->addr + ((i * frame->line_len + j * (frame->bpp / 8)) / 4));
			if ((write(g_bmp_fd, &pxl, 4)) != 4)
				err_exit(ERRTYPE_BMP);
			j++;
		}
		i--;
	}
}

static void	bmp_header(t_frame *frame, int imgsize)
{
	extern int	g_bmp_fd;
	uint8_t		header[54];
	int			filesize;

	filesize = imgsize + 54;
	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &filesize, 4);
	ft_memcpy(header + 10, &(int){54}, 4);
	ft_memcpy(header + 14, &(int){40}, 4);
	ft_memcpy(header + 18, &frame->game->map->res_x, 4);
	ft_memcpy(header + 22, &frame->game->map->res_y, 4);
	ft_memcpy(header + 26, &(int){1}, 2);
	ft_memcpy(header + 28, &(int){32}, 2);
	ft_memcpy(header + 34, &imgsize, 4);
	if ((write(g_bmp_fd, header, 54)) != 54)
		err_exit(ERRTYPE_BMP);
}

void		frame_save(t_frame *frame)
{
	extern int	g_bmp_fd;
	int			imgsize;

	imgsize = frame->game->map->res_y * frame->game->map->res_x * 4;
	if ((g_bmp_fd = open(SAVE_FILE, O_WRONLY | O_CREAT, S_IRWXU)) < 0)
		err_exit(ERRTYPE_BMP);
	bmp_header(frame, imgsize);
	bmp_data(frame);
	close(g_bmp_fd);
	g_bmp_fd = -1;
}
