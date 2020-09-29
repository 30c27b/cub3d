/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:46:32 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/29 15:20:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ************************************************************************** **
**                                                                            **
**                                             ______      __   _____ ____    **
**                                            / ____/_  __/ /_ |__  // __ \   **
**                                           / /   / / / / __ \ /_ </ / / /   **
**                                          / /___/ /_/ / /_/ /__/ / /_/ /    **
** Cub3D                                    \____/\__,_/_.___/____/_____/     **
** 2020 Antoine Coulon @ s19                                                  **
** ************************************************************************** **
*/

#ifndef CUB3D_H
# define CUB3D_H

/*
** Standard libraries ******************************************************* **
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

/*
** External libraries ******************************************************* **
*/

# include "libraries/libft/libft.h"
# include "libraries/mlx/mlx.h"

/*
** Classes ****************************************************************** **
*/

# include "classes/t_rgb.h"
# include "classes/t_file.h"
# include "classes/t_map.h"
# include "classes/t_vect.h"
# include "classes/t_fvect.h"
# include "classes/t_view.h"
# include "classes/t_win.h"
# include "classes/t_inst.h"
# include "classes/t_frame.h"
# include "classes/t_game.h"

/*
** Handlers *** ************************************************************* **
*/

# include "handlers/err_exit.h"
# include "handlers/frame_loop.h"
# include "handlers/hooks.h"

/*
** Definitions ************************************************************** **
*/

# define C3D_TITLE "Cub3D"

# define WIN_MAX_W 2560
# define WIN_MAX_H 1440

#endif
