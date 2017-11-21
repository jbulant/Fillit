/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_mgr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/21 02:45:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_us				revers_bit(t_us tetri)
{
	t_us	rev;
	int		i;

	rev = 0;
	i = -1;
	while (++i < 16)
		rev |= (!!(tetri & (1 << (15 - i)))) << i;
	return (rev);
}

static void				set_size(t_piece *piece)
{
	int		i;

	i = 0;
	while ((MSK_HRZ >> (i * 4)) & piece->value && i < 4)
		i++;
	piece->max_y = i;
	i = 0;
	while ((MSK_VRT >> (i * 1)) & piece->value && i < 4)
		i++;
	piece->max_x = i;
}

static t_us				atosint(const char *tetrimino)
{
	t_us			ret;
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
	if (!ret)
		return (0);
	while (!(ret & MSK_VRT))
		ret <<= 1;
	while (!(ret & MSK_HRZ))
		ret <<= 4;
	return (ret);
}

static unsigned long	us_to_ul(t_us mino)
{
	unsigned long	ul_mino;

	mino = revers_bit(mino);
	ul_mino = (mino & 0xF) | ((mino & 0xF0) << 12)
				| ((unsigned long)(mino & 0xF00) << (24))
				| ((unsigned long)(mino & 0xF000) << (36));
	return (ul_mino);
}

t_piece					create_piece(char *tetrimino)
{
	t_piece new;

	new.value = atosint(tetrimino);
	set_size(&new);
	new.mask = us_to_ul(new.value);
	new.pos_x = 0;
	new.pos_y = 0;
	return (new);
}
