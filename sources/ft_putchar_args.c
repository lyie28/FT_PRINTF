/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:32:02 by lyie              #+#    #+#             */
/*   Updated: 2021/01/06 17:24:51 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar_args(char c, int flags[5])
{
	int count;

	count = flags[2] - 1;
	if (flags[2] != 0)
	{
		if (flags[1] == 0 && (!(flags[0] == 1 && c == '%')))
			ft_charprinter(count, ' ');
		if (flags[0] == 1 && c == '%' && flags[1] == 0)
			ft_charprinter(count, '0');
		write(1, &c, 1);
		if (flags[1] == 1)
			ft_charprinter(count, ' ');
	}
	else
		write(1, &c, 1);
	if (flags[2] > 1)
		return (flags[2]);
	return (1);
}
