/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:14:12 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/06 18:01:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(t_list *el1, t_list *el2)
{
	void	*tmp;

	tmp = el1->content;
	el1->content = el2->content;
	el2->content = tmp;
}

void		ft_lstsort(t_list **lst, int (*f)(void *, void *, void *),
void *data)
{
	int		swapped;
	t_list	*el;

	if (!lst || !*lst)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		el = *lst;
		while (el->next != NULL)
		{
			if (f(el->content, el->next->content, data) > 0)
			{
				swap(el, el->next);
				swapped = 1;
			}
			el = el->next;
		}
	}
}
