/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_err.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:03:11 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/09 15:21:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ************************************************************************** **
** Cub3D                                                                      **
** Copyright (c) 2020 Antoine Coulon                                          **
** ************************************************************************** **
*/

#ifndef C3D_ERR_H
# define C3D_ERR_H

# define ERR_PREFIX "Error: "
# define ERR_SUFFIX "\n"

# define ERRTYPE_MLX "The graphical library could not work properly."
# define ERRTYPE_NOMEM "The system ran out of memory."
# define ERRTYPE_NOARG "One to two arguments are required."
# define ERRTYPE_BADARG "One or more arguments are invalid."
# define ERRTYPE_NOMAP "The map does not exist."
# define ERRTYPE_BADMAP "The provided map is incorrect."

void			err_exit(char *msg);

#endif
