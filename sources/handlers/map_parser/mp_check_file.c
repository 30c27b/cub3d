/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:13:51 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/11 11:54:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void	mp_del_empty(t_map_file *file)
{
	t_list	*el;
	t_list	tmp;

	el = file->data;
	while (el)
	{
		if (!el->content || !el->content[0])
			ft_lstdelone(el, &free);
	}
}

void		mp_check_file(t_map_file *file)
{
	if (ft_lstsize(file->data) < 11)
		err_exit(ERRTYPE_BADMAP);
}
