/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_move_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:18:24 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 15:05:37 by anouvel          ###   ########.fr       */
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

int			ft_m_move_up(int ***m)
{
	int	x;
	int y;
	int xx;
	int ret;

	ret = 0;
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
				if ((ft_m_move_replace_x(m, x, y, xx)) == 1)
					ret = 1;
			}
			x++;
		}
	}
	return (ret);
}
