/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:20:22 by anouvel           #+#    #+#             */
/*   Updated: 2015/03/01 11:24:59 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

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
