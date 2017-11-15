/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/15 12:42:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

t_suint	atosint(const char *tetrimino)
{
	t_suint			 ret;
	unsigned int	c_count;
	size_t			i;

	ret = 0;
	c_count = 0;
	i = 20;
	while (i)
	{
		if (tetrimino[i - 1] == '#')
			ret |= 1 << c_count;
		if (tetrimino[i - 1] != '\n')
			c_count++;
		i--;
	}
	while (!(ret & 0x8888))
		ret <<= 1;
	while (!(ret & 0xF000))
		ret <<= 4;
	return (ret);
}

t_bool	buf_check(const char *buf)
{
	unsigned int i;

	i = 0;
	while (buf[i])
	{
		if ( i % 5 == 4 && buf[i] != '\n')
			return (FALSE);
		if (buf[i] != '.' && buf[i] != '#' &&  buf[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		parse(int fd)
{
	static char		buf[BUFF_SIZE + 1];
	static t_suint	tetri_tab[26];
	int				ret;
	int				i;

	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 1)
	{
		buf[ret] = '\0';
		if (!buf_check(buf))
		{
			ft_putstr("error\n");
			return (NULL);
		}
		tetri_tab[i++] = atosint(buf);
	}
}

int		main(int ac, const char **av)
{
	int fd;

	if (ac != 2)
	{
		ft_putendl(USAGE);
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	parse(fd);
	return (0);
}
