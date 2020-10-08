/* ************************************************************************** */
/*														                    */
/*                                                        :::      ::::::::   */
/*   frame_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:53:56 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/30 13:35:17 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_print(t_frame_ray ray)
{
	printf("cam: %f\ndir: %f ; %f\ntile %ld ; %ld\n", ray.cam, ray.dir.x, ray.dir.y, ray.tile.x, ray.tile.y);
	printf("delta_dist: %f ; %f\nside_dist: %f ; %f\n", ray.delta_dist.x, ray.delta_dist.y, ray.side_dist.x, ray.side_dist.y);
}

static t_frame_ray	ray_process_init(t_frame *frame, size_t x)
{
	t_frame_ray	ray;
	ray.cam = 2 * x / (double)frame->game->map->res_x - 1;
	ray.dir = fvect_addv(frame->game->view->dir,
	fvect_mult(frame->game->view->fov, ray.cam));
	ray.tile = vect_fromf(frame->game->view->pos);
	ray.delta_dist = fvect_init(fabs(1 / ray.dir.x), fabs(1 / ray.dir.y));
	ray.hit = 0;
	ray.step.x =  (ray.dir.x < 0) ? -1 : 1;
	ray.step.y =  (ray.dir.y < 0) ? -1 : 1;
	if (ray.dir.x < 0)
		ray.side_dist.x = (frame->game->view->pos.x - ray.tile.x) * ray.delta_dist.x;
	else
		ray.side_dist.x = (ray.tile.x + 1.0 - frame->game->view->pos.x) * ray.delta_dist.x;
	if (ray.dir.y < 0)
		ray.side_dist.y = (frame->game->view->pos.y - ray.tile.y) * ray.delta_dist.y;
	else
		ray.side_dist.y = (ray.tile.y + 1.0 - frame->game->view->pos.y) * ray.delta_dist.y;
	ray_print(ray);
	return (ray);
}

static void			ray_dda(t_frame *frame, t_frame_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->tile.x += ray->step.x;
			ray->wall_side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->tile.y += ray->step.y;
			ray->wall_side = 1;
		}
		if (frame->game->map->content[ray->tile.x][ray->tile.y])
			ray->hit = TRUE;
	}
	//printf("tile %ld %ld\n", ray->tile.x, ray->tile.y);
	//printf("raydir %f %f\n", ray->dir.x, ray->dir.y);
	if (!ray->wall_side)
	{
		ray->wall_dist = (ray->tile.x - frame->game->view->pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
	}
	else
	{
		ray->wall_dist = (ray->tile.y - frame->game->view->pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
	}
	//printf("wd: %f\n", ray->wall_dist);
}

static void			ray_draw(t_frame *frame, t_frame_ray *ray, size_t x)
{
	int		line_h;
	int		line_top;
	t_rgb	color;

	line_h = (int)(frame->game->map->res_y / ray->wall_dist);
	line_top = -line_h / 2 + frame->game->map->res_y / 2;
	if (ray->wall_side == 1)
		color = rgb_init(255, 50, 50);
	else
		color = rgb_init(50, 255, 50);
	printf("put: %d - %d\n", line_top, line_h);
	frame_put_line(frame, vect_init(x, line_top), line_h, color);
}

static void			ray_process(t_frame *frame, size_t x)
{
	t_frame_ray	ray;

	ray = ray_process_init(frame, x);
	ray_dda(frame, &ray);
	ray_draw(frame, &ray, x);
}

void				frame_loop(t_game *game)
{
	t_frame		*frame;
	int		i;

	frame = frame_init(game);
	i = 0;
	printf("res_x_: %d\n", game->map->res_x);
	while (i < game->map->res_x)
		ray_process(frame, i++);
	frame_push(frame);
	frame_free(frame);
	exit(0);
}
