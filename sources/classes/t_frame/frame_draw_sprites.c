/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_draw_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:12:10 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/11 16:01:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cmp_sprites(void *spr1, void *spr2, void *data)
{
	t_sprite	*s1;
	t_sprite	*s2;
	t_game		*game;
	double		dst1;
	double		dst2;

	s1 = (t_sprite *)spr1;
	s2 = (t_sprite *)spr2;
	game = (t_game *)data;
	dst1 = ((game->view->pos.x - s1->pos.x) * (game->view->pos.x - s1->pos.x)
	+ (game->view->pos.y - s1->pos.y) * (game->view->pos.y - s1->pos.y));
	dst2 = ((game->view->pos.x - s2->pos.x) * (game->view->pos.x - s2->pos.x)
	+ (game->view->pos.y - s2->pos.y) * (game->view->pos.y - s2->pos.y));
	return (dst1 < dst2);
}

static void	process_sprites(t_game *game, t_frame_sp *fsp)
{
	fsp->s = (t_sprite *)fsp->el->content;
	fsp->sprite_x = fsp->s->pos.x - game->view->pos.x;
	fsp->sprite_y = fsp->s->pos.y - game->view->pos.y;
	fsp->inv_det = 1.0 / (game->view->fov.x * game->view->dir.y -
	game->view->dir.x * game->view->fov.y);
	fsp->transform_x = fsp->inv_det * (game->view->dir.y *
	fsp->sprite_x - game->view->dir.x * fsp->sprite_y);
	fsp->transform_y = fsp->inv_det * (-game->view->fov.y *
	fsp->sprite_x + game->view->fov.x * fsp->sprite_y);
	fsp->sprite_screen_x = (int)((game->map->res_x / 2) *
	(1 + fsp->transform_x / fsp->transform_y));
	fsp->sprite_height = abs((int)(game->map->res_y /
	(fsp->transform_y)));
	fsp->draw_start_y = -fsp->sprite_height / 2 + game->map->res_y / 2;
	if (fsp->draw_start_y < 0)
		fsp->draw_start_y = 0;
	fsp->draw_end_y = fsp->sprite_height / 2 + game->map->res_y / 2;
	if (fsp->draw_end_y >= game->map->res_y)
		fsp->draw_end_y = game->map->res_y - 1;
	fsp->sprite_width = abs((int)(game->map->res_y / (fsp->transform_y)));
	fsp->draw_start_x = -fsp->sprite_width / 2 + fsp->sprite_screen_x;
	if (fsp->draw_start_x < 0)
		fsp->draw_start_x = 0;
	fsp->draw_end_x = fsp->sprite_width / 2 + fsp->sprite_screen_x;
}

static void	draw_sprites(t_frame *frame, t_game *game, t_frame_sp *fsp)
{
	while (fsp->stripe < fsp->draw_end_x)
	{
		fsp->tex_x = (int)(256 * (fsp->stripe - (-fsp->sprite_width /
		2 + fsp->sprite_screen_x)) * TEX_WIDTH / fsp->sprite_width) / 256;
		if (fsp->transform_y > 0 && fsp->stripe > 0 && fsp->stripe
		< game->map->res_x && fsp->transform_y <
		frame->z_buffer[fsp->stripe])
		{
			fsp->y = fsp->draw_start_y;
			while (fsp->y < fsp->draw_end_y)
			{
				fsp->d = (fsp->y) * 256 - game->map->res_y * 128 +
				fsp->sprite_height * 128;
				fsp->tex_y = ((fsp->d * TEX_HEIGHT) /
				fsp->sprite_height) / 256;
				fsp->color = texture_get_pixel(game->map->tx_s,
				vect_init(fsp->tex_x, fsp->tex_y));
				if ((rgb_to_int(fsp->color) & 0x00FFFFFF) != 0)
					frame_put_pixel(frame,
					vect_init(fsp->stripe, fsp->y), fsp->color);
				fsp->y++;
			}
		}
		fsp->stripe++;
	}
}

void		frame_draw_sprites(t_frame *frame)
{
	t_game		*game;
	t_frame_sp	fsp;

	game = frame->game;
	ft_bzero(&fsp, sizeof(t_frame_sp));
	ft_lstsort(&game->map->sprites, &cmp_sprites, game);
	fsp.el = game->map->sprites;
	while (fsp.el)
	{
		process_sprites(game, &fsp);
		if (fsp.draw_end_x >= game->map->res_x)
			fsp.draw_end_x = game->map->res_x - 1;
		fsp.stripe = fsp.draw_start_x;
		draw_sprites(frame, game, &fsp);
		fsp.el = fsp.el->next;
	}
}
