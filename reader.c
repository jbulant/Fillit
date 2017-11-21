/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/21 02:47:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		draw_map(t_piece *tetrimino)
{
	int				size;
	unsigned short	map[16];

	ft_bzero(map, sizeof(unsigned short) * 16);
	size = begin_size(tetrimino);
	while (!(ft_back(tetrimino, size, map, 0)))
		size++;
	print_tab(tetrimino, --size);
}

int				parse(int fd)
{
	static char		buf[BUFF_SIZE + 1];
	static t_piece	tetri_tab[26];
	char			lastbuf[BUFF_SIZE + 1];
	int				ret;
	int				i;

	i = 0;
	while (i < 26 || (i = 0))
		tetri_tab[i++].value = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 1)
	{
		buf[ret] = '\0';
		tetri_tab[i] = create_piece(buf);
		if (!buf_check(buf) || !is_valid(tetri_tab[i].value))
			return (-1);
		ft_strcpy(lastbuf, buf);
		i++;
	}
	if (ft_strlen(lastbuf) != 20)
		return (-1);
	draw_map(tetri_tab);
	return (0);
}
