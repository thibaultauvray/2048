/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:15:50 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 16:54:48 by anouvel          ###   ########.fr       */
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

static int	ft_init(int ***m)
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

int			main(void)
{
	int **m;
	int	ret;

	m = NULL;
	ret = ft_init(&m);
	if (ret == 1)
		ft_putendl_fd("error -> WIN_VALUE must be <= to pow(2, 17)", 2);
	else if (ret == 2)
		ft_putendl_fd("error -> cannot initialize the map", 2);
	else if (((ft_check_win_value(MAX_VALUE)) == 1 || MAX_VALUE < WIN_VALUE))
		ft_putendl_fd("error -> MAX_VALUE not valid", 2);
	else
		ft_play_the_game(&m);
	return (0);
}
