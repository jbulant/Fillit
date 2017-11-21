/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:59:52 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/21 02:47:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 21
# define USAGE "usage: ./fillit source_file"
# define MSK_HRZ 0xF000
# define MSK_VRT 0x8888

typedef unsigned short		t_us;

typedef struct			s_piece
{
	t_us			value;
	int				pos_x;
	int				pos_y;
	int				max_x;
	int				max_y;
	unsigned long	mask;
}						t_piece;
void					print_tab(t_piece *tetri, int grid_size);
int						parse(int fd);
t_piece					create_piece(char *tetrimino);
t_bool					buf_check(const char *buf);
t_bool					ft_back(t_piece *tab, int size, t_us *map, int lvl);
int						begin_size(t_piece *tab);
int						is_valid(t_us value);
#endif
