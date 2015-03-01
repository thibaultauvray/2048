/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:46:53 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/01 14:51:20 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void		ft_print_b(void)
{
	getmaxyx(stdscr, m_y, m_x);
	mvprintw(m_y / 2, m_x / 2, "YOU FAILED");
}

void	ft_print_error(int	i)
{
	if (i == 1);
		ft_print_b();
}
