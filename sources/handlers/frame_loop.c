/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:53:56 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 14:53:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		frame_loop(t_game *game)
{
	(void)game;
	// size_t	i;
	// double	cam;
	// t_vect	ray_dir;
	// t_vect	round_pos;
	// t_vect	side_dist;
	// t_vect	delta_dist;
	// t_bool	ray_hit;
	// t_bool	hit_side;

	// i = 0;
	// while (i < game->map->res_x)
	// {
	// 	cam = 2 * i / (double)game->map->res_x - 1;
	// 	ray_dir = vect_addv(game->view.direction, vect_mult(game->view.fov, cam));
	// 	round_pos = vect_init(floor(game->view.position.x), floor(game->view.position.y));
	// 	delta_dist = vect_init(fabs(1 / ray_dir.x), fabs(1 / ray_dir.y));
	// 	i++;
	// }
}
