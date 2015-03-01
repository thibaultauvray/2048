/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:19:34 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 16:07:57 by tauvray          ###   ########.fr       */
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
	WIN_VALUE = 8,
	MAX_VALUE = 16
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

int		print_grille(int ***tab);

void	ft_array_del(int ***m);
void	ft_print_error(int i);

#endif
