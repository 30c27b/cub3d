/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:46:32 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 16:38:28 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ************************************************************************** **
** Cub3D                                                                      **
** 2020 Antoine Coulon @ s19                                                  **
** ************************************************************************** **
*/

#ifndef CUB3D_H
# define CUB3D_H

/*
** Libraries **************************************************************** **
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
** Extern libraries ********************************************************* **
*/

# include "libraries/libft/libft.h"
# include "libraries/mlx/mlx.h"

/*
** Classes ****************************************************************** **
*/

# include "classes/t_rgb.h"
# include "classes/t_map.h"
# include "classes/t_win.h"
# include "classes/t_inst.h"

/*
** Others ******************************************************************* **
*/

# include "err_exit.h"

/*
** Definitions ************************************************************** **
*/

# define C3D_TITLE "Cub3D"

#endif
