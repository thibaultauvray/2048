/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:32:41 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/01 15:01:52 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void	draw_square(int x, int y, int p, int p2, int tab)
{
	int	x1;
	int y1;
	int	mo_x;
	int	mo_y;

	x1 = x;
	y1 = y;
	mo_x = (x + p) / 2;
	mo_y = (y + p2) / 2;
	attron(A_BOLD);
	if (tab != 0)
		mvprintw(mo_y, mo_x, "%i", tab);
	attroff(A_BOLD);
	while (y1 <= p2)
	{
		while (x1 <= p)
		{
			if (x1 == p || x1 == x)
				mvprintw(y1, x1, "|");
			if ((y1 == p2 && x1 <= p) || y1 == y)
				mvprintw(y1, x1, "-");
			x1++;
		}
		x1 = 0;
		y1++;
	}
}

int		print_grille(int ***tab)
{
	int	x;
	int	y;
	int m_x;
	int	m_y;
	int	p;
	int	p2;
	int	i;
	int	o;

	i = 1;
	o = 1;
	getmaxyx(stdscr, m_y, m_x);
	m_y--;
	m_x--;
	if (m_y < 9 || m_x < 35)
		return (-1);
	while (i <= 4)
	{
		while (o <= 4)
		{
			x = (m_x / 4 ) * (i - 1);
			y = (m_y / 4) * (o - 1);
			p = (m_x / 4) * i;
			p2 = (m_y / 4) * o;
			draw_square(x, y, p, p2, (*tab)[o - 1][i - 1]);
			o++;
		}
		o = 1;
		i++;
	}
	return (0);
}
