/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:26:40 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 21:11:53 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void	ft_play_the_game(int ***m)
{
	int key;
	WINDOW *screen;

	ft_a_add_value(m);
	ft_a_add_value(m);

	if (!(screen = initscr()))
		return ;
	noecho();
	curs_set(FALSE);
	keypad(screen, TRUE);
	print_grille(*m);
	// int ret = 0;
	// while (ret == 0);
	while (1)
	{
		key = getch();
		if (key == KEY_UP)
		{
			// ret = ft_m_select(m, KEY_UP);
			ft_m_select(m, KEY_UP);
			clear();
			print_grille(*m);
		}
		else if (key == KEY_DOWN)
		{
			ft_m_select(m, KEY_DOWN);
			clear();
			print_grille(*m);
		}
		else if (key == KEY_LEFT)
		{
			ft_m_select(m, KEY_LEFT);
			clear();
			print_grille(*m);
		}
		else if (key == KEY_RIGHT)
		{
			ft_m_select(m, KEY_RIGHT);
			clear();
			print_grille(*m);
		}
		else if (key == ECHP)
		{
			ft_array_del(m);
			break ;
		}
		else
			ft_putendl("tutu");
		// if (ret == 1) // alors bloque
		// print fail -> exit
		// mettre un booleen "winValue atteinte
		// else if (ret = WIN_VALUE && bool == FALSE) -> do stg
		// else if (ret = WIN_MAX) -> stop
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
