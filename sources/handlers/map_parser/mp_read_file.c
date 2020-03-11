/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:13:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/11 11:07:50 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		mp_read_file(t_map_file *file)
{
	char		*line;
	t_list		*el;
	
	if ((file->fd = open(file->path, O_RDONLY)) < 0)
		err_exit(ERRTYPE_NOMAP);
	while (get_next_line(file->fd, &line) > 0)
	{
		if (!(el = ft_lstnew((void *)line)))
		{
			ft_lstclear(&file->data, &free);
			err_exit(ERRTYPE_NOMEM);
		}
		ft_lstadd_back(&file->data, el);
	}
	if (!(el = ft_lstnew((void *)line)))
	{
		ft_lstclear(&file->data, &free);
		err_exit(ERRTYPE_NOMEM);
	}
	ft_lstadd_back(&file->data, el);
}
