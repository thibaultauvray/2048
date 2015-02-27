/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:11:51 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 14:44:09 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return (&(((char *)s)[len]));
		len--;
	}
	return (NULL);
}
