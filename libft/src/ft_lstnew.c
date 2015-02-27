/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:21:10 by anouvel           #+#    #+#             */
/*   Updated: 2014/11/11 12:28:33 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content)
	{
		list->content = ft_memalloc(content_size);
		list->content_size = content_size;
		ft_memcpy(list->content, content, content_size);
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	return (list);
}
