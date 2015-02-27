/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:41:45 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:41:46 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_ins(const char *s1, char c, const char *s2)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin_c(s1, c);
	ret = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
	return (ret);
}
