/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:03:00 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/23 13:47:39 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_args(int ac, char **av, t_file *file)
{
	if (ac < 2 || ac > 3)
		err_exit(ERRTYPE_NOARG);
	if (!av[1][0])
		err_exit(ERRTYPE_BADARG);
	if (ac == 3 && ft_strcmp("--save", av[2]))
		err_exit(ERRTYPE_BADARG2);
	file->save = (ac == 3) ? TRUE : FALSE;
	file->path = av[1];
}

t_file		*file_init(int ac, char **av)
{
	t_file	*file;
	char	*line;
	t_list	*el;

	file = malloc(sizeof(t_file));
	ft_memset(file, 0, sizeof(t_file));
	printf("created file\n");
	parse_args(ac, av, file);
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
	close(file->fd);
	printf("returned file\n");
	return (file);
}
