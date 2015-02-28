/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:32:41 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/28 18:06:33 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"
#include <string.h> 

void	print_grille(int **tab)
{
	int	x;
	int	y;
	int max_y;
	int max_x;
	int	m;
	int	m2;
	int	p;
	int	p2;
	int i;

	y = 0;
	x = 0;
	getmaxyx(stdscr, max_y, max_x);
	max_x--;
	max_y--;
	p = ((max_y - 5) / 4) / 2;
	p2 = ((max_x - 5) / 4) / 2;
	m = max_y / 4;
	m2 = max_x / 4;
	(void)i;
	(void)p;
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
			mvprintw(p, p2, "%i", tab[0][0]);
			mvprintw(p, p2 + (2 * p2), "%i", tab[0][1]);
			mvprintw(p, p2 + (4 * p2), "%i", tab[0][2]);
			mvprintw(p, p2 + (6 * p2), "%i", tab[0][3]);

			mvprintw(p + (2 * p), p2, "%i", tab[1][0]);
			mvprintw(p + (2 * p), p2 + (2 * p2), "%i", tab[1][1]);
			mvprintw(p + (2 * p), p2 + (4 * p2), "%i", tab[1][2]);
			mvprintw(p + (2 * p), p2 + (6 * p2), "%i", tab[1][3]);

			mvprintw(p + (4 * p), p2, "%i", tab[2][0]);
			mvprintw(p + (4 * p), p2 + (2 * p2), "%i", tab[2][1]);
			mvprintw(p + (4 * p), p2 + (4 * p2), "%i", tab[2][2]);
			mvprintw(p + (4 * p), p2 + (6 * p2), "%i", tab[2][3]);

			mvprintw(p + (6 * p), p2, "%i", tab[3][0]);
			mvprintw(p + (6 * p), p2 + (2 * p2), "%i", tab[3][1]);
			mvprintw(p + (6 * p), p2 + (4 * p2), "%i", tab[3][2]);
			mvprintw(p + (6 * p), p2 + (6 * p2), "%i", tab[3][3]);
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
}

void	print_curse(void)
{
	int key;
	WINDOW *screen;

	screen = initscr();
	noecho();
	curs_set(FALSE);
	keypad(screen, TRUE);
	while (1)
	{
		key = getch();
		if (key == KEY_UP)
		{
			mvprintw(10, 10, "KEY UP");
		}
		if (key == KEY_DOWN)
		{
			mvprintw(10, 10, "KEY DOWN");
		}
		if (key == KEY_LEFT)
		{
			mvprintw(10, 10, "KEY LEFT");
		}
		if (key == KEY_RIGHT)
		{
			mvprintw(10, 10, "KEY RIGHT");
		}
		if (key == ECHP)
			break ;
	}
	endwin();
}
void	aff_grille(int y, int x)
{
	int	c_x;
	int	c_y;

	c_x = 0;
	c_y = 0;
	while (c_y <= y)
	{
		while (c_x <= x)
		{
			if (c_y % 4 == 0)
				mvaddch(c_x, c_y, '-');
			x++;
		}
		x = 0;
		y++;
	}
}
