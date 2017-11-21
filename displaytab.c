/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/21 02:44:46 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init_map(char *map, int size)
{
	int i;

	ft_memset(map, '.', size * (size + 1));
	map[size * (size + 1)] = '\0';
	i = 0;
	while (i < size)
		map[size + (i++ * (size + 1))] = '\n';
}

void			print_tab(t_piece *tetri, int size)
{
	char	map[273];
	int		i;
	int		x;
	int		y;

	init_map(map, size);
	i = -1;
	while (tetri[++i].mask)
	{
		y = -1;
		while (++y < tetri[i].max_y)
		{
			x = -1;
			while (++x < size)
			{
				if (tetri[i].mask & (1UL << (x + (y * 16))))
					map[x + ((y + tetri[i].pos_y) * (size + 1))] = 'A' + i;
			}
		}
	}
	ft_putstr(map);
}
