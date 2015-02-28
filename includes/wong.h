/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:19:34 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 20:14:43 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WING_H
#define WONG_H

#include <libft.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define ECHP	27

enum	e_const
{
		WIN_VALUE = 2048
};


void	ft_a_add_value(int ***m);
int		ft_a_blocked(int ***m);

void 	ft_m_select(int ***, int flag);
int		ft_m_move_left(int ***m);
int		ft_m_move_right(int ***m);
int		ft_m_move_up(int ***m);
int		ft_m_move_down(int ***m);
int		ft_m_push_left(int ***m);
int		ft_m_push_right(int ***m);
int		ft_m_push_up(int ***m);
int		ft_m_push_down(int ***m);


int		ft_init(int ***m);
void	print_grille(int **tab);

void	ft_array_del(int ***m);
void	ft_array_print(int **m);

#endif
