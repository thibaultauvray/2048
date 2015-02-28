/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:35:41 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 20:15:53 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void ft_m_select(int ***m, int flag)
{
	int retm;
	int retp;

	if (flag == 0)
	{
		retm = ft_m_move_down(m);
		retp = ft_m_push_down(m);
	}
	else if (flag == 1)
	{
		retm = ft_m_move_up(m);
		retp = ft_m_push_up(m);
	}
	else if (flag == 2)
	{
		retm = ft_m_move_left(m);
		retp = ft_m_push_left(m);
	}
	else
	{
		retm = ft_m_move_right(m);
		retp = ft_m_push_right(m);
	}
	if (retm == 1 || retp == 1)
		ft_a_add_value(m);
}
