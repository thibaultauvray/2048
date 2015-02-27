/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:26:23 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:28:31 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_c(const char *s1, char c)
{
	char	*ret;
	size_t	i;

	i = ft_strlen(s1);
	if (!(ret = ft_strnew(i + 1)))
		return (NULL);
	ft_strcpy(ret, s1);
	ret[i] = c;
	return (ret);
}
