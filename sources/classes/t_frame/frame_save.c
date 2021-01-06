/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:21:46 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/06 16:29:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bdata(t_frame *frame, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = frame->game->map->res_x * (frame->game->map->res_y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < frame->game->map->res_x)
		{
			buffer[0] = (unsigned char)(frame->addr[i] % 256);
			buffer[1] = (unsigned char)(frame->addr[i] / 256 % 256);
			buffer[2] = (unsigned char)(frame->addr[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2*frame->game->map->res_x;
	}
}

void	ft_binfo(t_frame *frame, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = frame->game->map->res_x;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = frame->game->map->res_y;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(t_frame *frame, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = frame->game->map->res_x * frame->game->map->res_y * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void		frame_save(t_frame *frame)
{
	int		fd;


	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(frame, fd);
	ft_binfo(frame, fd);
	ft_bdata(frame, fd);
	close(fd);
}

// void	bmp_data(t_frame *frame)
// {
// 	extern int	g_bmp_fd;
// 	int		i;
// 	int		j;
// 	uint8_t	buffer[4];

// 	i = frame->game->map->res_x * (frame->game->map->res_y - 1);
// 	while (i >= 0)
// 	{
// 		j = 0;
// 		while (j < frame->game->map->res_x)
// 		{
// 			buffer[0] = (unsigned char)(((unsigned int *)frame->addr)[i] % 256);
// 			buffer[1] = (unsigned char)(((unsigned int *)frame->addr)[i] / 256 % 256);
// 			buffer[2] = (unsigned char)(((unsigned int *)frame->addr)[i] / 256 / 256 % 256);
// 			buffer[3] = (unsigned char)(0);
// 			write(g_bmp_fd, buffer, 4);
// 			i++;
// 			j++;
// 		}
// 		i -= 2* frame->game->map->res_x;
// 	}
// }

// static void	bmp_header(t_frame *frame, int imgsize)
// {
// 	extern int	g_bmp_fd;
// 	uint8_t		header[54];
// 	int			filesize;
// 	unsigned int			h = 54;
// 	unsigned int			o = 40;

// 	filesize = imgsize + 54;
// 	ft_bzero(header, 54);
// 	ft_memcpy(header, "BM", 2);
// 	ft_memcpy(header + 2, &filesize, 4);
// 	ft_memcpy(header + 10, &h, 4);
// 	ft_memcpy(header + 14, &o, 4);
// 	ft_memcpy(header + 18, &frame->game->map->res_x, 4);
// 	ft_memcpy(header + 22, &frame->game->map->res_y, 4);
// 	ft_memcpy(header + 26, &(int){1}, 2);
// 	ft_memcpy(header + 28, &(int){32}, 2);
// 	ft_memcpy(header + 34, &imgsize, 4);
// 	if ((write(g_bmp_fd, header, 54)) < 54)
// 		err_exit(ERRTYPE_BMP);
// }

// void		frame_save(t_frame *frame)
// {
// 	extern int	g_bmp_fd;
// 	int			imgsize;

// 	imgsize = frame->game->map->res_y * ( (frame->game->map->res_x * 32 + 31) / 32 * 4 );
// 	if ((g_bmp_fd = open(SAVE_FILE, O_WRONLY | O_CREAT, S_IRWXU)) < 0)
// 		err_exit(ERRTYPE_BMP);
// 	bmp_header(frame, imgsize);
// 	bmp_data(frame);
// 	close(g_bmp_fd);
// 	g_bmp_fd = -1;
// }
