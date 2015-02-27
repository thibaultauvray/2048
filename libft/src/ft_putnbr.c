/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:01:30 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:03:21 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	temp;
	int	size;

	size = 1;
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		temp = n;
		while ((temp /= 10) > 0)
			size *= 10;
		temp = n;
		while (size)
		{
			ft_putchar((temp / size) + 48);
			temp %= size;
			size /= 10;
		}
	}
}
