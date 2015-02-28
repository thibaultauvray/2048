/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:26:40 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 20:34:44 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void	ft_play_the_game(int ***m)
{
	int key;
	WINDOW *screen;

	ft_a_add_value(m);
	ft_a_add_value(m);

	screen = initscr();
	noecho();
	curs_set(FALSE);
	keypad(screen, TRUE);
	print_grille(*m);
	while (1)
	{
		key = getch();
		if (key == KEY_UP)
		{
			ft_m_select(m, 1);
			clear();
			print_grille(*m);
		}
		if (key == KEY_DOWN)
		{
			ft_m_select(m, 0);
			clear();
			print_grille(*m);
		}
		if (key == KEY_LEFT)
		{
			ft_m_select(m, 2);
			clear();
			print_grille(*m);
		}
		if (key == KEY_RIGHT)
		{
			ft_m_select(m, 3);
			clear();
			print_grille(*m);
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
