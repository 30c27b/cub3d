/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:03:11 by ancoulon          #+#    #+#             */
/*   Updated: 2020/12/19 11:11:50 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_EXIT_H
# define ERR_EXIT_H

# define ERR_PREFIX "\033[38;5;196mError\n\033[38;5;247m"
# define ERR_SUFFIX "\033[0m\n"

# define ERRTYPE_MLX "The graphical library could not work properly."
# define ERRTYPE_NOMEM "The system ran out of memory."
# define ERRTYPE_NOARG "One to two arguments are required."
# define ERRTYPE_BADARG "One or more arguments are invalid."
# define ERRTYPE_BADARG2 "The second argument can only be '--save'."
# define ERRTYPE_NOMAP "The map does not exist."
# define ERRTYPE_BADMAP "The provided map is incorrect."
# define ERRTYPE_BADTEX "One or more of the provided textures are incorrect."
# define ERRTYPE_BMP "Could not save the screenshot to a file."

void			err_exit(char *msg);

#endif
