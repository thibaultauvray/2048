/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:19:07 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 20:34:30 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int	ft_check_win_value(int n)
{
	int	exp;

	if (n > 131072)
		return (1);
	exp = 0;
	while (exp <= 17)
	{
		if (n == (int)pow(2.0, exp))
			return (0);
		exp++;
	}
	return (1);
}

int			ft_init(int ***m)
{
	int	i;
	int	**ar;

	if ((ft_check_win_value(WIN_VALUE)) == 1)
		return (1);
	if (!(ar = (int **)malloc(sizeof(int *) * 4)))
		return (2);
	i = 0;
	while (i < 4)
	{
		if (!(ar[i] = (int *)malloc(sizeof(int) * 4)))
			return (2);
		ar[i][0] = 0;
		ar[i][1] = 0;
		ar[i][2] = 0;
		ar[i][3] = 0;
		i++;
	}
	*m = ar;
	return (0);
}
