/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:24:33 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 16:44:55 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void	ft_push_up(int ***m)
{
	int x;
	int y;
	int xx;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 3)
		{
			if ((*m)[x][y] == 0)
			{
				xx = x + 1;
				while (xx < 3 && (*m)[xx][y] == 0)
					xx++;
				(*m)[x][y] = (*m)[xx][y];
				(*m)[xx][y] = 0;
			}
			x++;
		}
		y++;
	}
}

void		ft_move_up(int ***m)
{
	int	x;
	int y;
	int xx;

	y = -1;
	while (++y < 4)
	{
		x = 0;
		while (x < 3)
		{
			if ((*m)[x][y] != 0)
			{
				xx = x + 1;
				while (xx < 3 && (*m)[xx][y] == 0)
					xx++;
				if ((*m)[x][y] == (*m)[xx][y])
				{
					(*m)[x][y] *= 2;
					(*m)[xx][y] = 0;
				}
			}
			x++;
		}
	}
	ft_push_up(m);
}
