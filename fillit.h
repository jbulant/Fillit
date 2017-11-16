/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:59:52 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/16 05:40:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include <stdbool.h>
typedef short unsigned int		t_suint;

typedef struct		s_piece
{
	t_suint		value;
	unsigned int	len;
	unsigned int	h;
	unsigned long	last_pos;
	unsigned long	number;
	unsigned int	index;
}							t_piece;
#define BUFF_SIZE 21
#define USAGE "usage: ./fillit source_file"

void							parse(int fd);
t_bool							buf_check(const char *buf);

#endif
