/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:32:41 by tauvray           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void	print_number(int max_x, int max_y, int ***tab)
{
	int		p;
	int		p2;
	int		x;
	int		y;
	int		o;
	int		q;

	x = 0;
	y = 0;
	p = ((max_y - 5) / 4) / 2;
	p2 = ((max_x - 5) / 4) / 2;
	o = 0;
	q = 0;
	while (y <= 3)
	{
		while (x <= 3)
		{
			attron(A_BOLD);
			if ((*tab)[y][x] != 0)
				mvprintw(p + (q * p), p2 + (o * p2), "%i", (*tab)[y][x]);
			attroff(A_BOLD);
			o = o + 2;
			x++;
		}
		q = q + 2;
		x = 0;
		o = 0;
		y++;
	}
	/*
	   mvprintw(p, p2, "%i", (*tab)[0][0]);
	   mvprintw(p, p2 + (2 * p2), "%i", (*tab)[0][1]);
	   mvprintw(p, p2 + (4 * p2), "%i", (*tab)[0][2]);
	   mvprintw(p, p2 + (6 * p2), "%i", (*tab)[0][3]);

	   mvprintw(p + (2 * p), p2, "%i", (*tab)[1][0]);
	   mvprintw(p + (2 * p), p2 + (2 * p2), "%i", (*tab)[1][1]);
	   mvprintw(p + (2 * p), p2 + (4 * p2), "%i", (*tab)[1][2]);
	   mvprintw(p + (2 * p), p2 + (6 * p2), "%i", (*tab)[1][3]);

	   mvprintw(p + (4 * p), p2, "%i", (*tab)[2][0]);
	   mvprintw(p + (4 * p), p2 + (2 * p2), "%i", (*tab)[2][1]);
	   mvprintw(p + (4 * p), p2 + (4 * p2), "%i", (*tab)[2][2]);
	   mvprintw(p + (4 * p), p2 + (6 * p2), "%i", (*tab)[2][3]);

	   mvprintw(p + (6 * p), p2, "%i", (*tab)[3][0]);
	   mvprintw(p + (6 * p), p2 + (2 * p2), "%i", (*tab)[3][1]);
	   mvprintw(p + (6 * p), p2 + (4 * p2), "%i", (*tab)[3][2]);
	   mvprintw(p + (6 * p), p2 + (6 * p2), "%i", (*tab)[3][3]);
	   */

}

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
	if (tab != 0)
		mvprintw(mo_y, mo_x, "%i", tab);
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

void	print_grille(int ***tab)
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
	(void)tab;
	getmaxyx(stdscr, m_y, m_x);
	m_y--;
	m_x--;
	//	x = m_x / 4;
	//	y = m_y / 4;
	x = (m_x / 4 ) * 0;
	y = m_y / 4;
	p = (m_x / 4) * 1;
	p2 = (m_y / 4) * 2;
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
	//	while (y <= p2)
	//	{
	//		while (x <= p)
	//		{
	//			if (x == p || x == (m_x / 4))
	//				mvprintw(y, x, "|");
	//			if ((y == p2 && x >= (m_x / 4)) || y == m_y / 4)
	//				mvprintw(y, x, "-");
	//			x++;
	//		}
	//		x = 0;
	//		y++;
	//	}
}

/*
   void	print_grille(int ***tab)
   {
   int	x;
   int	y;
   int max_y;
   int max_x;
   int	m;
   int	m2;
//	int	p;
//	int	p2;
int i;

y = 0;
x = 0;
getmaxyx(stdscr, max_y, max_x);
max_x--;
max_y--;
//	p = ((max_y - 5) / 4) / 2;
//	p2 = ((max_x - 5) / 4) / 2;
m = max_y / 4;
m2 = max_x / 4;
(void)i;
while (y <= max_y)
{
while (x <= max_x)
{
if ((y == 0 && x <= ((max_x / 4) * 4)) || (y == m && x <= ((max_x / 4) * 4)))
mvaddch(y, x, '-');
if ((x == 0 && y <= ((max_y / 4) * 4)) || (x == m2 && y <= ((max_y / 4) * 4)))
mvaddch(y, x, '|');
if (x == m2)
m2 = m2 + (max_x / 4);
print_number(max_x, max_y, tab);
x++;
}
if (y == m)
m = m + (max_y / 4);
y++;
m2 = max_x / 4;
x = 0;
}
x = 0;
y = 0;
}*/
