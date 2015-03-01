/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:21:42 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 19:14:50 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY 30000


/*
static void	ft_play_the_game(int ***m)
{
	ft_add_value(m);
	ft_add_value(m);

	ft_putstr("movement possible : ");
	if (ft_movement(m) == 0)
		ft_putendl("true");
	else
		ft_putendl("false");
	ft_array_print(*m);
	ft_array_del(m);
}
*/

static void	ft_play_the_game(int ***m)
{
	int key;
	WINDOW *screen;

	ft_add_value(m);
	ft_add_value(m);

	screen = initscr();
	noecho();
	curs_set(FALSE);
	keypad(screen, TRUE);
	while (1)
	{
		clear();
		print_grille(m);
		key = getch();
		if (key == KEY_UP)
		{
			mvprintw(10, 10, "KEY UP");
			ft_move_up(m);
			ft_add_value(m);
		}
		if (key == KEY_DOWN)
		{
			mvprintw(10, 10, "KEY DOWN");
			ft_move_down(m);
			ft_add_value(m);
		}
		if (key == KEY_LEFT)
		{
			mvprintw(10, 10, "KEY LEFT");
			ft_move_left(m);
			ft_add_value(m);
		}
		if (key == KEY_RIGHT)
		{
			mvprintw(10, 10, "KEY RIGHT");
			ft_move_right(m);
			ft_add_value(m);
		}
		if (key == ECHP)
		{
			ft_array_del(m);
			break ;
		}
	}
	endwin();
}

int			main(void)
{
	int **m;
	int	ret;

	m = NULL;
	ret = ft_init(&m);
	if (ret == 1)
		ft_putendl_fd("error -> WIN_VALUE must be <= to pow(2, 17)", 2);
	else if (ret == 2)
		ft_putendl_fd("error -> cannot initialize the map", 2);
	else
		ft_play_the_game(&m);
	return (0);
}
