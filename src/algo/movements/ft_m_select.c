/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:35:41 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 21:11:52 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void ft_m_select(int ***m, int flag)
{
	int retm;
	int retp;

	if (flag == KEY_DOWN)
	{
		retm = ft_m_move_down(m);
		retp = ft_m_push_down(m);
	}
	else if (flag == KEY_UP)
	{
		retm = ft_m_move_up(m);
		retp = ft_m_push_up(m);
	}
	else if (flag == KEY_LEFT)
	{
		retm = ft_m_move_left(m);
		retp = ft_m_push_left(m);
	}
	else
	{
		retm = ft_m_move_right(m);
		retp = ft_m_push_right(m);
	}
	// protect ft_a_add_value()
	if (retm == 1 || retp == 1)
		ft_a_add_value(m);
	// ft_blocked return (maxInt du tableau)
	// return (ft_a_blocked(m));
}
