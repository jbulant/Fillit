/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:39:49 by allauren          #+#    #+#             */
/*   Updated: 2017/11/21 02:48:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool		is_valid_pos(t_piece *tab, unsigned long *map)
{
	if (!(*map & tab->mask))
	{
		*map = *map ^ tab->mask;
		return (TRUE);
	}
	return (FALSE);
}

static int			count_tetri(t_piece *tab)
{
	int	i;

	i = 0;
	while (tab[i].value)
		i++;
	return (i);
}

int					begin_size(t_piece *tab)
{
	int	nb_tetri;
	int	sqrt;
	int	incr;
	int	odd;

	nb_tetri = 4 * count_tetri(tab);
	sqrt = 0;
	incr = 0;
	odd = 1;
	while (incr <= nb_tetri)
	{
		incr += odd;
		odd += 2;
		sqrt++;
	}
	if (((sqrt - 1) * (sqrt - 1)) == nb_tetri)
		sqrt--;
	return (sqrt);
}

t_bool				ft_back(t_piece *tab, int size, t_us *map, int lvl)
{
	t_piece	current;

	current = tab[lvl];
	current.max_y = size - tab[lvl].max_y;
	current.max_x = size - tab[lvl].max_x;
	current.pos_y = -1;
	while (++current.pos_y < current.max_y)
	{
		current.pos_x = -1;
		while (++current.pos_x < current.max_x)
		{
			if (is_valid_pos(tab + lvl, (unsigned long*)(map + current.pos_y)))
			{
				if (((!tab[lvl + 1].value || ft_back(tab, size, map, lvl + 1))
							&& ((tab[lvl].pos_y = current.pos_y) + 1)))
					return (TRUE);
				*(unsigned long*)(map + current.pos_y) ^= tab[lvl].mask;
			}
			tab[lvl].mask <<= 1;
		}
		if (current.max_x > 0)
			tab[lvl].mask >>= current.max_x;
	}
	return (FALSE);
}
