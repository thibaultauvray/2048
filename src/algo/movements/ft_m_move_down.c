/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_move_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:09:12 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 15:05:26 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int	ft_m_move_replace_x(int ***m, int x, int y, int xx)
{
	if ((*m)[x][y] == (*m)[xx][y])
	{
		(*m)[x][y] *= 2;
		(*m)[xx][y] = 0;
		return (1);
	}
	return (0);
}

int			ft_m_move_down(int ***m)
{
	int	x;
	int y;
	int xx;
	int ret;

	ret = 0;
	y = -1;
	while (++y < 4)
	{
		x = 3;
		while (x > 0)
		{
			if ((*m)[x][y] != 0)
			{
				xx = x - 1;
				while (xx > 0 && (*m)[xx][y] == 0)
					xx--;
				if ((ft_m_move_replace_x(m, x, y, xx)) == 1)
					ret = 1;
			}
			x--;
		}
	}
	return (ret);
}
