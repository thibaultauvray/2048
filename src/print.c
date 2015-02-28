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
			if ((*tab)[y][x] != 0)
				mvprintw(p + (q * p), p2 + (o * p2), "%i", (*tab)[y][x]);
			o = o + 2;
			x++;
			mvprintw(50, 50, "%i", (p + (q * p)));
		}
		q = q + 2;
		x = 0;
		o = 0;
		y++;
	}
}

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
}
