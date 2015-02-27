/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:09:00 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:18:12 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		first_index(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	return (i);
}

static int		find_sign(const char *str, int i)
{
	if (str[i] == '+')
		return (1);
	else if (str[i] == '-')
		return (-1);
	else if (ft_isdigit(str[i]) == 1)
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int sign;
	int res;
	int idx;

	idx = first_index(str);
	sign = find_sign(str, idx);
	res = 0;
	if (sign == 0)
		return (0);
	else
	{
		if (str[idx] == '+' || str[idx] == '-')
			idx++;
		while (str[idx] != '\0' && ft_isdigit(str[idx]))
		{
			res = res * 10 + (str[idx] - 48);
			idx++;
		}
	}
	return (res * sign);
}
