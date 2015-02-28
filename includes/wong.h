/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:19:34 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 19:01:10 by tauvray          ###   ########.fr       */
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

int		ft_init(int ***m);
void	ft_add_value(int ***m);
int		ft_movement(int ***m);
void	ft_move_left(int ***m);
void	ft_move_right(int ***m);
void	ft_move_up(int ***m);
void	ft_move_down(int ***m);

void	print_grille(int ***tab);

void	ft_array_del(int ***m);
void	ft_array_print(int **m);

#endif
