/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:40:49 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/23 14:08:13 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		file_print(t_file *file)
{
	t_list	*el;

	el = file->data;
	while (el)
	{
		ft_putstr_fd((char *)el->content, 1);
		ft_putchar_fd('\n', 1);
		el = el->next;
	}
}
