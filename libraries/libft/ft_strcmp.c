/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:39:39 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/10 11:02:53 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	while (s1_copy[i] == s2_copy[i])
	{
		if (s1_copy[i] == '\0')
			return (0);
		i++;
	}
	return (s1_copy[i] - s2_copy[i]);
}
