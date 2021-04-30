/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:38:00 by lyie              #+#    #+#             */
/*   Updated: 2021/01/15 15:46:00 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./includes/ft_printf.h"

void	ft_flag(int (*tab)[5], int flag_no, int value, int *i)
{
	if ((*tab)[flag_no] == 0)
		(*tab)[flag_no] = value;
	(*i)++;
}

int		ft_isconverter(char c)
{
	char	*accept;
	int		i;

	accept = "picsxXud%";
	i = 0;
	while (accept[i])
	{
		if (c == accept[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_fill(int (*tabs)[5])
{
	int i;

	i = -1;
	while (++i < 5)
		(*tabs)[i] = 0;
	return (1);
}
