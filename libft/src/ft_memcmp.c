/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:02:59 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 14:06:49 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		res;

	if (!s1 && !s2)
		return (0);
	res = 0;
	i = 0;
	while (i < n && res == 0)
	{
		res = (unsigned char)(((char *)s1)[i])
			- (unsigned char)(((char *)s2)[i]);
		i++;
	}
	return (res);
}
