/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:20:22 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/28 20:36:22 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void	ft_array_print(int **m)
{
	int i;
	int j;

	if (m == NULL)
		ft_putendl("NULL array");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(m[i][j]);
			ft_putstr(" | ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putendl("");
}

void	ft_array_del(int ***m)
{
	int		**ar;
	int		i;

	ar = *m;
	i = 0;
	while (i < 4)
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
	free(ar);
	ar = NULL;
}
