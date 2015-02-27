/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:03:44 by anouvel           #+#    #+#             */
/*   Updated: 2015/02/22 17:52:46 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	copy_line(char **line, char *buf)
{
	char	*c;
	char	*tmp;
	int		len;

	len = ft_strlen(buf);
	tmp = ft_strnew(len);
	if (!tmp)
		return (-1);
	ft_memccpy(tmp, buf, '\n', len);
	c = ft_strchr(tmp, '\n');
	if (c)
		*c = '\0';
	c = *line;
	*line = ft_strjoin(*line, tmp);
	ft_strdel(&c);
	ft_strdel(&tmp);
	if (!*line)
		return (-1);
	return (1);
}

static int	line_endl(char *buf)
{
	char	*str;

	if ((str = ft_strchr(buf, '\n')))
	{
		ft_strcpy(buf, (str + 1));
		return (1);
	}
	ft_strclr(buf);
	return (0);
}

static int	read_lines(int fd, char **line, char *buf)
{
	int	res;
	int	ret;

	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		ret = copy_line(line, buf);
		if (ret == -1)
			return (-1);
		if (line_endl(buf))
			return (1);
	}
	if (res == 0)
	{
		if (ft_strlen(*line))
			return (1);
		return (0);
	}
	return (-1);
}

static int	init_read(char **line)
{
	*line = ft_strnew(0);
	if (!*line)
		return (-1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	buf[BUFF_SIZE + 1];

	if (!line)
		return (-1);
	ret = init_read(line);
	if (ret == -1)
		return (-1);
	if (ft_strlen(buf))
	{
		ret = copy_line(line, buf);
		if (ret == -1)
			return (-1);
		if (line_endl(buf))
			return (1);
	}
	ret = read_lines(fd, line, buf);
	if (ret == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	else
		return (1);
}
