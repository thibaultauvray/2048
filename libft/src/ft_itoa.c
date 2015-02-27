/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:12:55 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 16:59:53 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = int_len(n);
	str = ft_memalloc(len + 1);
	str[len] = '\0';
	if (n == -2147483648)
		ft_strcpy(str, "-2147483648");
	else if (n == 0)
		ft_strcpy(str, "0");
	else
	{
		if (n < 0)
		{
			str[0] = '-';
			n = n * -1;
		}
		len--;
		while (n > 0)
		{
			str[len--] = (n % 10) + 48;
			n = n / 10;
		}
	}
	return (str);
}
