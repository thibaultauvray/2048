/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:33:10 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:19:10 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *ret;

	if (!(ret = ft_strnew(ft_strlen(s1))))
		return (NULL);
	ft_strcpy(ret, s1);
	return (ret);
}
