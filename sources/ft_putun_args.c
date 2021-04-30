/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:33:45 by lyie              #+#    #+#             */
/*   Updated: 2021/01/15 12:13:16 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n, int tab[5])
{
	int count;

	count = 0;
	if (n == 0 && (!(tab[3] == 1 && tab[4] == 0)))
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_start(unsigned int n, int tab[5], int *print_len)
{
	int t_len;
	int n_len;

	n_len = ft_numlen(n, tab);
	*print_len = n_len;
	if (tab[4] > *print_len && tab[3] == 1)
		*print_len = tab[4];
	t_len = *print_len;
	if (tab[2] > *print_len)
		t_len = tab[2];
	if (t_len > *print_len && tab[1] != 1 && (tab[3] == 1 || tab[0] == 0))
		ft_charprinter((tab[2] - *print_len), ' ');
	if (*print_len > n_len || (tab[3] == 0 && tab[0] == 1 && t_len > n_len))
	{
		if (tab[3] == 1)
			ft_charprinter((*print_len - n_len), '0');
		else
			ft_charprinter((t_len - n_len), '0');
	}
}

int			ft_putun_args(unsigned int n, int tab[5], int tracker)
{
	static int	print_len;

	if (tracker == 0)
		ft_start(n, tab, &print_len);
	if (n >= 10)
	{
		ft_putnbr_args((n / 10), tab, (tracker + 1));
		ft_putchar((n % 10) + '0');
	}
	else
	{
		if (!(tab[3] == 1 && tab[4] == 0 && n == 0))
			ft_putchar(n + '0');
	}
	if (tracker == 0 && tab[1] == 1)
		ft_charprinter((tab[2] - print_len), ' ');
	return ((tab[2] > print_len) ? tab[2] : print_len);
}
