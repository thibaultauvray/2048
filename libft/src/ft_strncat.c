/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:31:41 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 14:40:18 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i1;
	size_t i2;

	i1 = 0;
	i2 = 0;
	while (s1[i1] != '\0')
		i1++;
	while (s2[i2] != '\0' && i2 != n)
	{
		s1[i1] = s2[i2];
		i1++;
		i2++;
	}
	s1[i1] = '\0';
	return (s1);
}
