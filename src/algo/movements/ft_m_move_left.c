/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_move_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:17:46 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 15:05:30 by anouvel          ###   ########.fr       */
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

int			ft_m_move_left(int ***m)
{
	int	x;
	int y;
	int yy;
	int ret;

	ret = 0;
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
				if ((ft_m_move_replace_y(m, x, y, yy)) == 1)
					ret = 1;
			}
			y++;
		}
	}
	return (ret);
}
