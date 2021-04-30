/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:32:15 by lyie              #+#    #+#             */
/*   Updated: 2021/01/15 16:00:14 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_args(char *str, int flags[5])
{
	int i;
	int wordlen;

	i = -1;
	if (str == NULL)
	{
		str = "(null)";
		wordlen = 6;
	}
	else
		wordlen = ft_strlen(str);
	if ((flags[3] == 1) && (flags[4] < wordlen))
		wordlen = flags[4];
	if ((flags[1] == 0) & (flags[2] > wordlen))
		ft_charprinter(flags[2] - wordlen, ' ');
	while (++i < wordlen)
		write(1, &str[i], 1);
	if ((flags[1] == 1) && (flags[2] != 0))
		ft_charprinter(flags[2] - wordlen, ' ');
	if (flags[2] > wordlen)
		return (flags[2]);
	return (wordlen);
}
