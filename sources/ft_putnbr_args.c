/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:33:45 by lyie              #+#    #+#             */
/*   Updated: 2021/01/14 16:27:36 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n, int tab[5])
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = (n * -1);
		count++;
	}
	if (n == 0 && (!(tab[3] == 1 && tab[4] == 0)))
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr_int_min(int tab[5])
{
	int	p_len;

	p_len = 11;
	if ((tab[2] > 11 && tab[1] != 1) && (tab[3] == 1 || tab[0] == 0))
		ft_charprinter((tab[2] - p_len), ' ');
	write(1, "-", 1);
	if (tab[4] > 11 || (tab[2] > 11 && tab[3] == 0 && tab[1] == 0))
	{
		p_len = tab[4];
		if (tab[2] > p_len)
			ft_charprinter(tab[2] - 11, '0');
		else
			ft_charprinter(tab[4] - 11, '0');
	}
	write(1, "2147483648", 10);
	if (tab[2] > p_len && tab[1] == 1)
		ft_charprinter((tab[2] - p_len), ' ');
	return (tab[2] > p_len ? tab[2] : p_len);
}

static void	ft_start(int n, int tab[5], int *p_len)
{
	int total_len;
	int n_len;

	n_len = ft_numlen(n, tab);
	*p_len = n_len;
	if (tab[4] >= *p_len && tab[3] == 1)
	{
		*p_len = tab[4];
		if (n < 0)
			*(p_len) = *(p_len) + 1;
	}
	total_len = *p_len;
	if (tab[2] > *p_len)
		total_len = tab[2];
	if (total_len > *p_len && tab[1] != 1 && (tab[3] == 1 || tab[0] == 0))
		ft_charprinter((tab[2] - *p_len), ' ');
	if (n < 0)
		write(1, "-", 1);
	if (*p_len > n_len || (tab[3] == 0 && tab[0] == 1 && total_len > n_len))
	{
		if (tab[3] == 1)
			ft_charprinter((*p_len - n_len), '0');
		else
			ft_charprinter((total_len - n_len), '0');
	}
}

int			ft_putnbr_args(int n, int tab[5], int tracker)
{
	static int	p_len;

	if (n == INT_MIN)
		return (ft_putnbr_int_min(tab));
	if (tracker == 0)
		ft_start(n, tab, &p_len);
	if (n < 0)
		n = n * -1;
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
		ft_charprinter((tab[2] - p_len), ' ');
	return ((tab[2] > p_len) ? tab[2] : p_len);
}
