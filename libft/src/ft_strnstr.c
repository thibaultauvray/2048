/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:18:34 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 15:43:11 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	r_len;
	size_t	l_len;
	size_t	i;

	if (s2 == NULL)
		return ((char *)s1);
	r_len = ft_strlen(s2);
	l_len = ft_strlen(s1);
	if (r_len > n)
		r_len = n;
	if (l_len < r_len)
		return (NULL);
	if (r_len == 0 || l_len == 0)
		return ((char *)s1);
	i = 0;
	while (*s1 != '\0' && (i + r_len) <= n)
	{
		if (ft_strncmp(s1, s2, r_len) == 0)
			return ((char *)s1);
		s1 += 1;
		++i;
	}
	return (NULL);
}
