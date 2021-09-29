/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:39:57 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/08 17:05:41 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEX "0123456789abcdef"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putchar_non_printable(unsigned char c)
{
	int	d0;
	int	d1;

	if (c < ' ' || c > 126)
	{
		d0 = c / 16;
		d1 = c % 16;
		ft_putchar ('\\');
		ft_putchar (HEX[c / 16]);
		ft_putchar (HEX[c % 16]);
	}
	else
	{
		write(1, &c, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_non_printable((unsigned char)str[i]);
		i += 1;
	}
}
