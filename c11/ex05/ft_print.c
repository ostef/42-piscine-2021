/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:22:57 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/13 02:16:49 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print(char *str)
{
	write (1, str, ft_strlen (str));
}

static unsigned int	ft_int_to_uint(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_print_number(int n)
{
	unsigned int	un;
	char			buffer[10];
	int				i;

	if (n == 0)
	{
		write (1, "0", 1);
	}
	else
	{
		if (n < 0)
			write (1, "-", 1);
		un = ft_int_to_uint (n);
		i = 0;
		while (un)
		{
			buffer[99 - i] = '0' + (un % 10);
			un /= 10;
			i += 1;
		}
		write (1, &buffer[100 - i], i);
	}
}
