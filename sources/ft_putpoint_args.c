/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:51:14 by lyie              #+#    #+#             */
/*   Updated: 2021/01/15 15:59:39 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_pointer_counter(unsigned long pointer, int tabs[5])
{
	int count;

	count = 0;
	if (pointer == 0 && tabs[3] == 0)
		return (3);
	if (pointer == 0 && tabs[3] == 1)
		return (2);
	while (pointer >= 16)
	{
		count++;
		pointer = pointer / 16;
	}
	if (pointer > 0)
		count++;
	return (count + 2);
}

static int	ft_end(unsigned long p, int tabs[5], int t, int num_len)
{
	if (tabs[1] == 1 && tabs[2] > num_len)
	{
		if (t == 2 || (t == 3 && p < 16 && !(p == 0 && tabs[3] == 1)))
			ft_charprinter(tabs[2] - num_len, ' ');
	}
	if (tabs[2] > num_len)
		return (tabs[2]);
	return (num_len);
}

int			ft_putpoint_args(unsigned long pointer, int tabs[5], int tracker)
{
	char		*base;
	static int	num_len;

	base = "0123456789abcdef";
	if (tracker == 0)
		num_len = ft_pointer_counter(pointer, tabs);
	if (tabs[2] > num_len && tabs[1] == 0 && tracker == 0)
		ft_charprinter(tabs[2] - num_len, ' ');
	if (tracker == 0)
	{
		write(1, "0x", 2);
		tracker = tracker + 2;
	}
	if (pointer < 16 && (!(pointer == 0 && tabs[3] == 1 && tracker == 2)))
	{
		ft_putchar(base[pointer]);
		tracker = tracker + 1;
	}
	if (pointer >= 16)
	{
		ft_putpoint_args(pointer / 16, tabs, tracker + 1);
		ft_putchar(base[pointer % 16]);
	}
	return (ft_end(pointer, tabs, tracker, num_len));
}
