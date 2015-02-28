/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:32:41 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/28 18:26:48 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

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
