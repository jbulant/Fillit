/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:59:52 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/14 05:17:43 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#define BUFF_SIZE 21
#define USAGE "usage: ./fillit source_file"
typedef short unsigned int		t_suint;

void							parse(int fd);
t_bool							buf_check(const char *buf);

#endif
