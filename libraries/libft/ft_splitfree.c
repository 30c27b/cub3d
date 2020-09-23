/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:39:24 by ancoulon          #+#    #+#             */
/*   Updated: 2020/09/23 14:25:44 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splitfree(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		ft_bzero(strs[i], ft_strlen(strs[i]));
		free(strs[i]);
		i++;
	}
	free(strs);
}
