/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:51:14 by lyie              #+#    #+#             */
/*   Updated: 2021/01/12 15:09:22 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_fig_count(unsigned int pointer, int *count, int tabs[5])
{
	if (pointer == 0)
	{
		if (tabs[3] == 1)
			return (0);
		else
			return (1);
	}
	if (pointer < 16)
		(*(count))++;
	if (pointer >= 16)
	{
		(*(count))++;
		ft_fig_count(pointer / 16, count, tabs);
	}
	return (*count);
}

static void	ft_stop_the_count(int *n_len, int tabs[5], unsigned int pointer)
{
	int param;
	int p_len;

	param = 0;
	*n_len = ft_fig_count(pointer, &param, tabs);
	if (tabs[4] > *n_len && tabs[3] == 1)
		p_len = tabs[4];
	else
		p_len = *n_len;
	if (tabs[2] > p_len && tabs[1] != 1 && (tabs[3] == 1 || tabs[0] == 0))
		ft_charprinter((tabs[2] - p_len), ' ');
	if (p_len > *n_len || (tabs[3] == 0 && tabs[0] == 1 && tabs[2] > *n_len))
	{
		if (tabs[3] == 1)
			ft_charprinter((tabs[4] - *n_len), '0');
		else
			ft_charprinter((tabs[2] - *n_len), '0');
	}
}

int			ft_puthex_lower_args(unsigned int pointer, int tabs[5], int tracker)
{
	char		*base;
	static int	n_len;
	static int	print_len;

	base = "0123456789abcdef";
	if (tracker == 0)
	{
		n_len = 0;
		ft_stop_the_count(&n_len, tabs, pointer);
		print_len = n_len;
		if (tabs[4] > n_len && tabs[3] == 1)
			print_len = tabs[4];
	}
	if (pointer < 16 && (!(pointer == 0 && tabs[3] == 1)))
		ft_putchar(base[pointer]);
	else if (pointer >= 16)
	{
		ft_puthex_lower_args(pointer / 16, tabs, tracker + 1);
		ft_putchar(base[pointer % 16]);
	}
	if (tracker == 0 && tabs[1] == 1 && tabs[2] > print_len)
		ft_charprinter((tabs[2] - print_len), ' ');
	if (tabs[2] > print_len)
		return (tabs[2]);
	return (print_len);
}
