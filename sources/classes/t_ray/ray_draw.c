/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:29:52 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 16:46:57 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_texture(t_ray *ray, t_game *game)
{
	if (ray->draw_s < 0)
		ray->draw_s = 0;
	ray->draw_e = ray->line_h / 2 + game->map->res_y / 2;
	if (ray->draw_e >= game->map->res_y)
		ray->draw_e = game->map->res_y - 1;
	if (ray->wall_side == 0)
		ray->wall_tex = game->map->tx_we;
	else if (ray->wall_side == 1)
		ray->wall_tex = game->map->tx_ea;
	else if (ray->wall_side == 2)
		ray->wall_tex = game->map->tx_no;
	else if (ray->wall_side == 3)
		ray->wall_tex = game->map->tx_so;
	else
		ray->wall_tex = game->map->tx_no;
	if (ray->wall_side < 2)
		ray->wall_x = game->view->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = game->view->pos.x + ray->wall_dist * ray->dir.x;
}

static void	sweep_ray(t_ray *ray, t_frame *frame, t_game *game)
{
	ray->screen_y = 0;
	while (ray->screen_y < game->map->res_y)
	{
		if (ray->screen_y < ray->draw_s)
			frame_put_pixel(frame, vect_init(ray->screen_x,
			ray->screen_y), game->map->cl_ceiling);
		else if (ray->screen_y >= ray->draw_s &&
		ray->screen_y <= ray->draw_e)
		{
			ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
			ray->tex_pos += ray->tx_step;
			frame_put_pixel(frame, vect_init(ray->screen_x, ray->screen_y),
			texture_get_pixel(ray->wall_tex,
			vect_init(ray->tex_x, ray->tex_y)));
		}
		else
			frame_put_pixel(frame, vect_init(ray->screen_x,
			ray->screen_y), game->map->cl_floor);
		ray->screen_y++;
	}
}

void		ray_draw(t_ray *ray, t_frame *frame, t_game *game)
{
	check_texture(ray, game);
	ray->wall_x -= floor((ray->wall_x));
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->wall_side < 2 && ray->dir.x > 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	if (ray->wall_side >= 2 && ray->dir.y < 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	ray->tx_step = 1.0 * TEX_HEIGHT / ray->line_h;
	ray->tex_pos = (ray->draw_s - game->map->res_y /
	2 + ray->line_h / 2) * ray->tx_step;
	frame->z_buffer[ray->screen_x] = ray->wall_dist;
	sweep_ray(ray, frame, game);
}
