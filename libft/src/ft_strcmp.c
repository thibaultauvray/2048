/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:28:36 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 15:35:27 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int cmp;

	if (!s1 && !s2)
		return (0);
	cmp = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && cmp == 0)
	{
		cmp = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
		i++;
	}
	return (cmp);
}
