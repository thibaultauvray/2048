/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:20:20 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 16:20:41 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void			ft_print_b(char *res)
{
	int	m_x;
	int	m_y;
	int	x;
	int	y;

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLUE);
	getmaxyx(stdscr, m_y, m_x);
	x = (m_x / 2) - 20;
	y = (m_y / 2) - 5;
	attron(COLOR_PAIR(1));
	while (x < (m_x / 2) + 20)
	{
		while (y < (m_y / 2) + 5)
		{
			mvprintw(y, x, " ");
			y++;
		}
		y = (m_y / 2) - 5;
		x++;
	}
	attron(A_BOLD);
	mvprintw((m_y / 2) - 2, (m_x / 2) - 5, "%s", res);
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
}

void				ft_p_print_error(int i)
{
	if (i == 1)
		ft_print_b("YOU FAILED");
	if (i == 2)
		ft_print_b("YOU WIN - Continue ?");
	if (i == 3)
		ft_print_b("YOU ARE A GENIOUS");
	refresh();
}
