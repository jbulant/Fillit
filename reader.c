/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 00:34:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_valide(t_suint value)
{
	static	t_suint all[19] = {61440, 34952, 52224, 51328, 57856, 17600, 36352,
	35008, 59392, 50240, 11776, 50688, 19584, 35904, 27648, 35968, 58368,
	19520, 19968};
	int	i;

	i = 0;
	while (i < 19)
	{
		if (value == all[i]) 
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	buf_check(const char *buf)
{
	unsigned int i;
	
	i = 0;
	while (buf[i])
	{
		if ( i % 5 == 4 && buf[i] != '\n')
		{	
			return (FALSE);
		}
		if (buf[i] != '.' && buf[i] != '#' &&  buf[i] != '\n')
		{
			return (FALSE);
		}
			i++;
	}
	return (TRUE);
}

void	draw_map(t_piece *tetrimino)
{
//	static unsigned long map[4];

//	ft_bzero(map, 32);

	for (int i = 0; i < 26; i++)
	{
		if (tetrimino[i].value == 0)
			break ;
		ft_print_ultobits(tetrimino[i].mask);
		ft_putchar('\n');
	}
}

void			parse(int fd)
{
	static char		buf[BUFF_SIZE + 1];
	static t_piece	tetri_tab[26];
	int				ret;
	int				i;

	i = 0;
	while (i < 26)
		tetri_tab[i++].value = 0;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 1)
	{
		buf[ret] = '\0';
		if (!buf_check(buf))
		{
			ft_putstr("error\n");
			return ;
		}
		tetri_tab[i++] = create_piece(buf);
	}
	draw_map(tetri_tab);
}

int				main(int ac, const char **av)
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




/*
void		ft_error(t_suint r, int i, t_piece *tab)
{
	if(r == 61440 && (tab[i].h = 1))
		tab[i].len = 4;
	if(r == 52224 && (tab[i].h = 2))
		tab[i].len = 2;
	if((r == 59392 || r ==36352 || r == 11776 || r == 57856 || r == 19968) 
			&& (tab[i].h= 2))
		tab[i].len = 3;
	if(r == 34952 && (tab[i].h = 4))
			tab[i].len = 1;
	if((r == 19584 || r == 35904 || r == 27648 || r ==35968) && (tab[i].h = 4))
		tab[i].len = 2;
	if((r == 51328 || r == 17600 || r == 35008
		|| r ==50240 || r == 58368 || r == 19520) && (tab[i].h = 3))
		tab[i].len = 2;
	if (r == 19968 && (tab[i].h = 2))
		tab[i].len = 3;
	if(tab[i].len)
		tab[i].value = r;
}

*/
