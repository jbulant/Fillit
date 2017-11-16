/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 00:23:41 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void				set_size(t_piece *piece)
{
	t_suint	msk_hrz;
	t_suint	msk_vrt;
	int		i;

	msk_hrz = 0xF000;
	msk_vrt = 0X8888;
	i = 0;
	while (msk_hrz & piece->value && i < 4)
	{
		msk_hrz >>= 4;
		i++;
	}
	piece->max_y = i;
	i = 0;
	while (msk_vrt & piece->value && i < 4)
	{
		msk_vrt >>= 1;
		i++;
	}
	piece->max_x = i;
}

static t_suint			atosint(const char *tetrimino)
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

static unsigned long	sui_to_ul(t_suint mino)
{
	unsigned long	ul_mino;
	unsigned long	mask;
	int				i;

	ul_mino = (unsigned long)mino;
	ul_mino <<= 48;
	mask = 0xFFFFFFFFFFFFFFF;
	i = 0;
	while (i++ < 4)
	{
		ul_mino = (ul_mino & ~mask) | (ul_mino >> 12 & mask);
		mask >>= 16;
	}
	ul_mino = (ul_mino & 0xF000F000F000F000);
	return (ul_mino);
}

t_piece					create_piece(char *tetrimino)
{
	t_piece new;

	new.value = atosint(tetrimino);
	set_size(&new);
	new.mask = sui_to_ul(new.value);
	return (new);
}
