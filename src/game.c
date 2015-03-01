/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:26:40 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 14:49:28 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void	ft_play_the_game(int ***m)
{
	int key;
	WINDOW *screen;
	int ret;
	int ret_win;

	ret_win = 1;
	ft_a_add_value(m);
	ft_a_add_value(m);

	if (!(screen = initscr()))
		return ;
	noecho();
	curs_set(FALSE);
	keypad(screen, TRUE);
	print_grille(m);
	ret = ft_m_max(m);
	while (ret != 0)
	{
		clear();
		print_grille(m);
		key = getch();
		if (key == KEY_UP)
			ret = ft_m_action(m, KEY_UP);
		else if (key == KEY_DOWN)
			ret = ft_m_action(m, KEY_DOWN);
		else if (key == KEY_LEFT)
			ret = ft_m_action(m, KEY_LEFT);
		else if (key == KEY_RIGHT)
			ret = ft_m_action(m, KEY_RIGHT);
		else if (key == ECHP)
		{
			ft_array_del(m);
			break ;
		}
		else
		{
		}

		if (ret == 0)
		{
			clear();
			print_grille(m);
			mvprintw(20, 20, "%s", "blocked");
			refresh();
			sleep(40);
		}
		else if (ret == WIN_VALUE && ret_win == 1)
		{
			mvprintw(20, 20, "%s", "you win");
			refresh();
			ret_win = 0;
		}
		else if (ret == MAX_VALUE)
		{
			mvprintw(20, 20, "%s", "you finished the game");
			refresh();
			sleep(10);
			ret = 0;
		}
		else
		{
		}
	}
	endwin();
}

static int	ft_check_win_value(int n)
{
	int	exp;

	if (n > 131072)
		return (1);
	exp = 0;
	while (exp <= 17)
	{
		if (n == (int)pow(2.0, exp))
			return (0);
		exp++;
	}
	return (1);
}

static int	ft_init(int ***m)
{
	int	i;
	int	**ar;

	if ((ft_check_win_value(WIN_VALUE)) == 1)
		return (1);
	if (!(ar = (int **)malloc(sizeof(int *) * 4)))
		return (2);
	i = 0;
	while (i < 4)
	{
		if (!(ar[i] = (int *)malloc(sizeof(int) * 4)))
			return (2);
		ar[i][0] = 0;
		ar[i][1] = 0;
		ar[i][2] = 0;
		ar[i][3] = 0;
		i++;
	}
	*m = ar;
	return (0);
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
