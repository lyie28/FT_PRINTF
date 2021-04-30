/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_edit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:37:35 by lyie              #+#    #+#             */
/*   Updated: 2021/01/15 14:03:47 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stddef.h>
#include <stdlib.h>

int	ft_substr_edit(char const *s, unsigned int start, size_t len)
{
	char	*finalstr;
	size_t	i;

	if (!(s))
		return (0);
	if (start >= ft_strlen((char *)s))
		len = 0;
	else if ((ft_strlen((char *)&s[start])) < len)
		len = ft_strlen((char *)&s[start]) + 1;
	if (!(finalstr = malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i < len && (s[start + i]))
	{
		finalstr[i] = s[start + i];
		i++;
	}
	finalstr[i] = '\0';
	ft_putstr(finalstr);
	free(finalstr);
	return (0);
}
