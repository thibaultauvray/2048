/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:35:20 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:19:50 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	else
	{
		if (s)
		{
			while (i < len)
			{
				str[i] = s[start];
				i++;
				start++;
			}
			str[i] = '\0';
			return (str);
		}
		else
			return (NULL);
	}
}
