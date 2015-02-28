/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_move_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:18:17 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 20:26:05 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int	ft_m_move_replace_y(int ***m, int x, int y, int yy)
{
	if ((*m)[x][y] == (*m)[x][yy])
	{
		(*m)[x][y] *= 2;
		(*m)[x][yy] = 0;
		return (1);
	}
	return (0);
}

int			ft_m_move_right(int ***m)
{
	int	x;
	int y;
	int yy;
	int ret;

	ret = 0;
	x = -1;
	while (++x < 4)
	{
		y = 3;
		while (y > 0)
		{
			if ((*m)[x][y] != 0)
			{
				yy = y - 1;
				while (yy > 0 && (*m)[x][yy] == 0)
					yy--;
				if ((ft_m_move_replace_y(m, x, y, yy)) == 1)
					ret = 1;
			}
			y--;
		}
	}
	return (ret);
}
