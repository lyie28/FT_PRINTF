/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:03:57 by lyie              #+#    #+#             */
/*   Updated: 2021/01/15 15:43:36 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi_edit(const char *string);
void	ft_flag(int (*tab)[5], int flag_no, int value, int *i);
int		ft_isconverter(char c);
int		ft_fill(int (*tabs)[5]);
int		ft_printf(const char *format, ...);
int		ft_isdigit(int c);
int		ft_putstr_args(char *str, int flags[5]);
void	ft_putstr(char *str);
int		ft_putpoint_args(long unsigned pointer, int tabs[5], int tracker);
int		ft_putun_args(unsigned int n, int tab[5], int tracker);
int		ft_puthex_lower_args(unsigned int pointer, int tabs[5], int tracker);
int		ft_puthex_upper_args(unsigned int pointer, int tabs[5], int tracker);
void	ft_charprinter(int times, char c);
int		ft_putchar_args(char c, int flags[5]);
void	ft_putchar(char c);
int		ft_putnbr_args(int n, int tab[5], int tracker);
int		ft_substr_edit(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);

#endif
