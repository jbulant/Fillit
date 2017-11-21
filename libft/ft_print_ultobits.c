/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/20 07:58:41 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_ultobits(unsigned long ul)
{
	char	bits_array[69];
	int		i;

	ft_memset(bits_array, '0', 68);
	bits_array[16] = '\n';
	bits_array[33] = '\n';
	bits_array[50] = '\n';
	bits_array[67] = '\n';
	bits_array[68] = '\0';
	i = 0;
	while (ul > 0)
	{
		if (bits_array[i] != '\n')
		{
			bits_array[i] = ul % 2 + '0';
			ul /= 2;
		}
		i++;
	}
	ft_putstr(bits_array);
}
