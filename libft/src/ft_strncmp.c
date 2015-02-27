/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:00:33 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:00:57 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	if (!s1 && !s2)
		return (0);
	i = 0;
	cmp = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && cmp == 0)
	{
		cmp = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
		i++;
	}
	return (cmp);
}
