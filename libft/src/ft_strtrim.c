/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:00:59 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:20:28 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first(const char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			&& str[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

static int	last(const char *str)
{
	int res;
	int i;

	res = ft_strlen(str);
	i = ft_strlen(str) - 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
	{
		res--;
		i--;
	}
	if (res == 0)
		return (ft_strlen(str));
	return (res);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s)
	{
		i = first(s);
		j = last(s);
		if (!(str = ft_strnew(ft_strlen(s) - i - (ft_strlen(s) - j) + 1)))
			return (NULL);
		k = 0;
		while (i < j)
		{
			str[k] = s[i];
			i++;
			k++;
		}
		return (str);
	}
	else
		return (NULL);
}
