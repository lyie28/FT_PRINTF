/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:21:16 by lyie              #+#    #+#             */
/*   Updated: 2021/01/15 15:55:52 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./includes/ft_printf.h"

static void	ft_format(const char *str, int (*tabs)[5], int *i)
{
	while (str[(*i)] == '0')
		ft_flag(tabs, 0, 1, i);
	while (str[(*i)] == '-')
		ft_flag(tabs, 1, 1, i);
	while (ft_isdigit(str[(*i)]) || str[(*i)] == '*' || str[(*i)] == '-')
		ft_flag(tabs, 2, (ft_atoi_edit(&str[(*i)])), i);
	while (str[(*i)] == '.')
		ft_flag(tabs, 3, 1, i);
	while (ft_isdigit(str[(*i)]) || str[(*i)] == '*')
		ft_flag(tabs, 4, (ft_atoi_edit(&str[(*i)])), i);
}

static void	ft_asterix(int index, int ast_value, int (*tabs)[5])
{
	if (ast_value < 0 && index == 2)
	{
		ast_value = (ast_value * -1);
		(*tabs)[1] = 1;
		(*tabs)[0] = 0;
		(*tabs)[2] = ast_value;
	}
	else if (ast_value < 0 && index == 4)
	{
		(*tabs)[4] = 0;
		(*tabs)[3] = 0;
	}
	else
		(*tabs)[index] = ast_value;
}

static void	ft_branch(char lookup, int arg, int tabs[5], int *len)
{
	if (lookup == 'c')
		*len = *len + (ft_putchar_args(arg, tabs));
	if (lookup == 'd' || lookup == 'i')
		*len = *len + (ft_putnbr_args(arg, tabs, 0));
	if (lookup == 'x')
		*len = *len + (ft_puthex_lower_args(arg, tabs, 0));
	if (lookup == 'X')
		*len = *len + (ft_puthex_upper_args(arg, tabs, 0));
}

int			ft_redirection(const char *new, va_list args, int *len, int *i)
{
	int		marker;
	int		tabs[5];

	marker = ft_fill(&tabs);
	ft_format(new, &tabs, &marker);
	if (tabs[2] == -1)
		ft_asterix(2, (va_arg(args, int)), &tabs);
	if (tabs[4] == -1)
		ft_asterix(4, (va_arg(args, int)), &tabs);
	if (new[marker] == 's')
		*len = *len + (ft_putstr_args(va_arg(args, char *), tabs));
	if (new[marker] == 'c' || new[marker] == 'd' || new[marker] == 'i')
		ft_branch(new[marker], va_arg(args, int), tabs, len);
	if (new[marker] == 'u')
		*len = *len + ft_putun_args(va_arg(args, unsigned), tabs, 0);
	if (new[marker] == 'X' | new[marker] == 'x')
		ft_branch(new[marker], va_arg(args, int), tabs, len);
	if (new[marker] == 'p')
		*len = *len + ft_putpoint_args((long)va_arg(args, void *), tabs, 0);
	if (new[marker] == '%')
		*len = *len + ft_putchar_args('%', tabs);
	*len = *len - marker - 1;
	*i = *i + marker;
	return ((!(ft_isconverter(new[marker]))) ? -1 : 0);
}

int			ft_printf(const char *format, ...)
{
	int		j;
	int		i;
	int		len;
	va_list	args;

	if (format == NULL)
		return (0);
	len = 0;
	j = 0;
	i = -1;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((ft_substr_edit(format, j, i - j)) == -1)
				return (j);
			if ((ft_redirection(&format[i], args, &len, &i)) == -1)
				return (i);
			j = i + 1;
		}
	}
	va_end(args);
	return ((ft_substr_edit(format, j, i - j) == -1) ? (j) : (len + i));
}
