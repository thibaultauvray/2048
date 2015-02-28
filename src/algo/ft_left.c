/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:03:03 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 16:44:53 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void	ft_push_left(int ***m)
{
	int x;
	int y;
	int yy;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 3)
		{
			if ((*m)[x][y] == 0)
			{
				yy = y + 1;
				while (yy < 3 && (*m)[x][yy] == 0)
					yy++;
				(*m)[x][y] = (*m)[x][yy];
				(*m)[x][yy] = 0;
			}
			y++;
		}
		x++;
	}
}

void		ft_move_left(int ***m)
{
	int	x;
	int y;
	int yy;

	x = -1;
	while (++x < 4)
	{
		y = 0;
		while (y < 3)
		{
			if ((*m)[x][y] != 0)
			{
				yy = y + 1;
				while (yy < 3 && (*m)[x][yy] == 0)
					yy++;
				if ((*m)[x][y] == (*m)[x][yy])
				{
					(*m)[x][y] *= 2;
					(*m)[x][yy] = 0;
				}
			}
			y++;
		}
	}
	ft_push_left(m);
}
