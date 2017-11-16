/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/16 06:56:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_ultobits(unsigned long ul)
{
	char bitsArray[69];
	int i;

	ft_memset(bitsArray, '0', 68);
	bitsArray[16] = '\n';
	bitsArray[33] = '\n';
	bitsArray[50] = '\n';
	bitsArray[67] = '\n';
	bitsArray[68] = '\0';
	i = 66;
	while (ul > 0)
	{
		if (bitsArray[i] != '\n')
		{
			bitsArray[i] = ul % 2 + '0';
			ul /= 2;
		}
		i--;
	}
	ft_putstr(bitsArray);
}
