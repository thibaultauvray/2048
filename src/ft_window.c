/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:46:42 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 16:48:31 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int	ft_init_win(int ***m)
{
	WINDOW *screen;

	ft_a_add_value(m);
	ft_a_add_value(m);
	if (!(screen = initscr()))
		return (1);
	noecho();
	curs_set(FALSE);
	keypad(screen, TRUE);
	return (0);
}

static int	ft_expose(int ***m, int err)
{
	clear();
	ft_p_print_grid(m);
	if (err == 1)
	{
		ft_p_print_error(1);
		refresh();
		sleep(2);
	}
	else if (err == 2)
	{
		ft_p_print_error(2);
		getch();
		refresh();
	}
	else if (err == 3)
	{
		ft_p_print_error(3);
		refresh();
		sleep(4);
	}
	return (0);
}

static int	ft_keyhook(int ***m, int key)
{
	int ret;

	ret = 0;
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
		ft_t_array_del(m);
		return (-1);
	}
	return (ret);
}

void		ft_play_the_game(int ***m)
{
	int key;
	int ret;
	int ret_win;

	ret = 0;
	if ((ft_init_win(m)) == 1)
		return ;
	ret = ft_m_max(m);
	ret_win = 1;
	while (ret != 0)
	{
		ft_expose(m, 0);
		key = getch();
		ret = ft_keyhook(m, key);
		if (ret == -1)
			break ;
		else if (ret == 0)
			ft_expose(m, 1);
		else if (ret == WIN_VALUE && ret_win == 1)
			ret_win = ft_expose(m, 2);
		else if (ret == MAX_VALUE)
			ret = ft_expose(m, 3);
	}
	endwin();
}
