/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:16:24 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/02 03:02:46 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_signed_to_positive(int n)
{
	unsigned int	un;

	if (n < 0)
		un = -n;
	else
		un = n;
	return (un);
}

void	ft_putnbr(int nb)
{
	char			buffer[100];
	int				length;
	unsigned int	un;

	un = ft_signed_to_positive(nb);
	if (un == 0)
	{
		ft_putchar('0');
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
		}
		length = 0;
		while (un > 0)
		{
			buffer[99 - length] = '0' + (un % 10);
			un /= 10;
			length += 1;
		}
		write(1, &buffer[100 - length], length);
	}
}
