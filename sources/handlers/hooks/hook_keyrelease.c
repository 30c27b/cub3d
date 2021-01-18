/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyrelease.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:56:02 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/18 14:38:42 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			hook_keyrelease(int keycode, void *param)
{
	t_view	*view;

	view = ((t_game *)param)->view;
	if (keycode == KEYCODE_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == KEYCODE_RIGTARROW)
		view->keyflag &= ~KEY_RIGTARROW;
	if (keycode == KEYCODE_LEFTARROW)
		view->keyflag &= ~KEY_LEFTARROW;
	if (keycode == KEYCODE_W)
		view->keyflag &= ~KEY_W;
	if (keycode == KEYCODE_A)
		view->keyflag &= ~KEY_A;
	if (keycode == KEYCODE_S)
		view->keyflag &= ~KEY_S;
	if (keycode == KEYCODE_D)
		view->keyflag &= ~KEY_D;
	return (0);
}
