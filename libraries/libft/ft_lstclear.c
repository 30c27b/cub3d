/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:42:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/05 15:54:10 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*el;
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	el = *lst;
	while (el)
	{
		tmp = el->next;
		ft_lstdelone(el, del);
		el = tmp;
	}
	*lst = NULL;
}
