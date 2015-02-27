/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:15:56 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:03:17 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int	temp;
	int	size;

	size = 1;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		temp = n;
		while ((temp /= 10) > 0)
			size *= 10;
		temp = n;
		while (size)
		{
			ft_putchar_fd((temp / size) + 48, fd);
			temp %= size;
			size /= 10;
		}
	}
}
