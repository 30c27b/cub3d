/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:03:00 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/28 12:10:36 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*parse_args(int ac, char **av, t_file *file)
{
	size_t	len;

	if (ac < 2 || ac > 3)
		err_exit(ERRTYPE_NOARG);
	if (!av[1][0])
		err_exit(ERRTYPE_BADARG);
	if (ac == 3 && ft_strcmp("--save", av[2]))
		err_exit(ERRTYPE_BADARG2);
	file->save = (ac == 3) ? TRUE : FALSE;
	len = ft_strlen(av[1]);
	if (len < 5)
		err_exit(ERRTYPE_BADARG);
	if (ft_strcmp(av[1] + (len - 4), ".cub"))
		err_exit(ERRTYPE_BADARG);
	return (av[1]);
}

t_file		*file_init(int ac, char **av)
{
	t_file		*file;
	char		*path;
	char		*line;
	t_list		*el;
	extern int	g_file_fd;

	if (!(file = malloc(sizeof(t_file))))
		err_exit(ERRTYPE_NOMEM);
	ft_memset(file, 0, sizeof(t_file));
	path = parse_args(ac, av, file);
	if ((g_file_fd = open(path, O_RDONLY)) < 0)
		err_exit(ERRTYPE_NOMAP);
	while (get_next_line(g_file_fd, &line) > 0)
	{
		if (!(el = ft_lstnew((void *)line)))
			err_exit(ERRTYPE_NOMEM);
		ft_lstadd_back(&file->data, el);
	}
	if (!(el = ft_lstnew((void *)line)))
		err_exit(ERRTYPE_NOMEM);
	ft_lstadd_back(&file->data, el);
	close(g_file_fd);
	g_file_fd = -1;
	return (file);
}
