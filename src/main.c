/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:21:42 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/27 22:40:28 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY 30000


int main (void)
{
	initscr();
	noecho();
	curs_set(FALSE);
	mvprintw(0, 0, "Hello, world!");
	refresh();
	sleep(1);
	endwin();
return (0);
}
