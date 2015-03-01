/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:19:34 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 18:06:07 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H

# include <libft.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>

# define ECHP	27

enum	e_const
{
	WIN_VALUE = 2048,
	MAX_VALUE = 131072
};

typedef struct	s_square
{
	int		x;
	int		y;
	int		m_x;
	int		m_y;
	int		p;
	int		p2;
	int		o;
	int		i;
}				t_square;

void	ft_play_the_game(int ***m);

void	ft_a_add_value(int ***m);
int		ft_a_blocked(int ***m);

int		ft_m_action(int ***m, int flag);
int		ft_m_max(int ***m);
int		ft_m_move_left(int ***m);
int		ft_m_move_right(int ***m);
int		ft_m_move_up(int ***m);
int		ft_m_move_down(int ***m);
int		ft_m_push_left(int ***m);
int		ft_m_push_right(int ***m);
int		ft_m_push_up(int ***m);
int		ft_m_push_down(int ***m);

int		ft_p_print_grid(int ***tab);
void	ft_p_print_error(int i);

void	ft_t_array_del(int ***m);

#endif
