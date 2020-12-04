/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:43:50 by ancoulon          #+#    #+#             */
/*   Updated: 2020/11/23 19:45:19 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			hook_keypress(int keycode, void *param)
{
	t_view	*view;

	view = ((t_game *)param)->view;
	if (keycode == KEYCODE_ESC)
		view->keyflag |= KEY_ESC;
	if (keycode == KEYCODE_RIGTARROW)
		view->keyflag |= KEY_RIGTARROW;
	if (keycode == KEYCODE_LEFTARROW)
		view->keyflag |= KEY_LEFTARROW;
	if (keycode == KEYCODE_W)
		view->keyflag |= KEY_W;
	if (keycode == KEYCODE_A)
		view->keyflag |= KEY_A;
	if (keycode == KEYCODE_S)
		view->keyflag |= KEY_S;
	if (keycode == KEYCODE_D)
		view->keyflag |= KEY_D;
	return (0);
}
