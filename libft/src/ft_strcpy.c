/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:39:53 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 14:26:35 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	if (!dst && !src)
		return (NULL);
	i = ft_strlen(src);
	if (src[i] && src[i] == '\0')
		dst[i] = '\0';
	while (i-- > 0)
		dst[i] = src[i];
	return (dst);
}
