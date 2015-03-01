/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:27:35 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 15:05:09 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int	ft_zero_line(int ***m, int x)
{
	int ret;
	int	y;

	ret = 0;
	y = 0;
	while (y < 4)
	{
		if ((*m)[x][y] == 0)
			ret++;
		y++;
	}
	return (ret);
}

static int	ft_zero_grid(int ***m)
{
	int ret;
	int x;
	int y;

	x = 0;
	ret = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if ((*m)[x][y] == 0)
				ret++;
			y++;
		}
		x++;
	}
	return (ret);
}

static int	ft_random_value(void)
{
	int	v;

	srand(time(NULL));
	v = rand() % 2;
	if (v == 0)
		return (2);
	else
		return (4);
}

static void	ft_put_value(int ***m, int x, int v)
{
	int y;

	y = 0;
	while ((*m)[x][y] != 0)
		y++;
	(*m)[x][y] = v;
}

void		ft_a_add_value(int ***m)
{
	int	v;
	int x;
	int y;

	if (ft_zero_grid(m) != 0)
	{
		v = ft_random_value();
		srand(time(NULL));
		x = rand() % 4;
		while (ft_zero_line(m, x) == 0)
			x = rand() % 4;
		if (ft_zero_line(m, x) == 1)
			ft_put_value(m, x, v);
		else
		{
			while (42)
			{
				if ((*m)[x][y = rand() % 4] == 0)
				{
					(*m)[x][y] = v;
					break ;
				}
			}
		}
	}
}
