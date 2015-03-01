/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:32:41 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/01 16:09:37 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void				draw_square(int x, int y, t_square t, int tab)
{
	t_square	s;

	s.x = x;
	s.y = y;
	s.m_x = (x + t.p) / 2;
	s.m_y = (y + t.p2) / 2;
	attron(A_BOLD);
	if (tab != 0)
		mvprintw(s.m_y, s.m_x, "%i", tab);
	attroff(A_BOLD);
	while (s.y <= t.p2)
	{
		while (s.x <= t.p)
		{
			if (s.x == t.p || s.x == x)
				mvprintw(s.y, s.x, "|");
			if ((s.y == t.p2 && s.x <= t.p) || s.y == y)
				mvprintw(s.y, s.x, "-");
			s.x++;
		}
		s.x = 0;
		s.y++;
	}
}

static t_square		init_square(t_square t)
{
	t.x = (t.m_x / 4) * (t.i - 1);
	t.y = (t.m_y / 4) * (t.o - 1);
	t.p = (t.m_x / 4) * t.i;
	t.p2 = (t.m_y / 4) * t.o;
	return (t);
}

int					print_grille(int ***tab)
{
	t_square	t;

	t.i = 1;
	t.o = 1;
	getmaxyx(stdscr, t.m_y, t.m_x);
	t.m_y--;
	t.m_x--;
	if (t.m_y < 9 || t.m_x < 35)
		return (-1);
	while (t.i <= 4)
	{
		while (t.o <= 4)
		{
			t = init_square(t);
			draw_square(t.x, t.y, t, (*tab)[t.o - 1][t.i - 1]);
			t.o++;
		}
		t.o = 1;
		t.i++;
	}
	return (0);
}
