/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dexec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:53:06 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/23 13:44:13 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_get_arguments(t_dex *e, int ac, char **av)
{
	char	**args;
	int		ac_i;
	int		i;

	ac_i = 1;
	while (ac_i < ac && av[ac_i][0] == '-')
		ac_i++;
	if (ac_i == ac || !(args = (char **)malloc(sizeof(char *) * (ac - ac_i))))
	{
		e->de_an = 0;
		e->de_a = NULL;
	}
	else
	{
		e->de_an = ac - ac_i;
		i = 0;
		while (ac_i < ac)
		{
			args[i] = ft_strdup(av[ac_i]);
			ac_i++;
			i++;
		}
		e->de_a = args;
	}
}

static void		ft_get_options(t_dex *e, int ac, char **av)
{
	char	*opts;
	char	*tmp_join;
	size_t	ac_i;

	if (!(opts = (char *)malloc(sizeof(char))))
		e->de_o = NULL;
	else
	{
		opts[0] = '\0';
		ac_i = 1;
		while ((int)ac_i < ac && av[ac_i][0] == '-')
		{
			tmp_join = ft_strjoin(opts, ft_strchr(av[ac_i], '-') + 1);
			free(opts);
			opts = ft_strdup(tmp_join);
			free(tmp_join);
			ac_i++;
		}
		e->de_o = opts;
	}
}

void			ft_put_dex(t_dex *e)
{
	size_t	i;

	if (e)
	{
		ft_putstr("executable     : ");
		ft_putendl(e->de_n);
		ft_putstr("options        : ");
		ft_putendl(e->de_o);
		ft_putendl("arguments      : ");
		i = 0;
		if (e->de_an != 0)
		{
			while (i < e->de_an)
			{
				ft_putstr((e->de_a)[i]);
				if (i != e->de_an - 1)
					ft_putstr(" - ");
				i++;
			}
		}
		write(1, "\n", 1);
	}
	else
		ft_putendl_fd("error -> cannot print the execution environment", 2);
}

void			ft_del_dex(t_dex *e)
{
	size_t	i;

	if (e)
	{
		if (e->de_n)
			free(e->de_n);
		if (e->de_o)
			free(e->de_o);
		if (e->de_a != NULL)
		{
			i = 0;
			while (i < e->de_an)
			{
				if ((e->de_a)[i] != NULL)
					free((e->de_a)[i]);
				i++;
			}
			free(e->de_a);
			e->de_a = NULL;
		}
		free(e);
		e = NULL;
	}
}

t_dex			*ft_get_dex(int ac, char **av)
{
	t_dex	*e;

	if (!(e = (t_dex *)malloc(sizeof(t_dex))))
		return (NULL);
	if (av[0])
	{
		e->de_n = ft_strdup(av[0]);
		ft_get_options(e, ac, av);
		ft_get_arguments(e, ac, av);
	}
	else
	{
		free(e);
		e = NULL;
	}
	return (e);
}
