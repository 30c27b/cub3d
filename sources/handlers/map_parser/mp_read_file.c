/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:13:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/10 15:23:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		mp_read_file(t_map_file *file)
{
	t_uint64	i;
	char		*line;
	t_list		*el;
	
	if (!(file->fd = open(file->path, O_RDONLY)))
		err_exit(ERRTYPE_NOMAP);
	while (ft_gnl(file->fd, &line))
	{
		if (!(el = ft_lstnew((void *)line)))
		{
			ft_lstclear(file->file, &free);
			err_exit(ERRTYPE_NOMEM);
		}
		ft_lstadd_back(file->file, el);
	}
}
