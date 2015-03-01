/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:19:40 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 15:22:12 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	r_len;
	size_t	l_len;

	r_len = ft_strlen(s2);
	l_len = ft_strlen(s1);
	if (l_len < r_len)
		return (NULL);
	if (r_len == 0 || l_len == 0)
		return ((char *)s1);
	while (*s1 != '\0')
	{
		if (ft_strncmp(s1, s2, r_len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
