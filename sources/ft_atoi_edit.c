/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_edit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:55:29 by lyie              #+#    #+#             */
/*   Updated: 2021/01/14 17:05:06 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_atoi_edit(const char *str)
{
	int i;
	int result;

	result = 0;
	i = 0;
	if (str[i] == '*')
		return (-1);
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (0);
	result = str[i] - '0';
	i++;
	while (str[i] > 47 && str[i] < 58)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}
