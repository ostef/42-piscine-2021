/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:49:47 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/04 17:31:25 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_signed_to_positive(int n)
{
	unsigned int	un;

	if (n < 0)
		un = -n;
	else
		un = n;
	return (un);
}

void	ft_putnbr(int n)
{
	unsigned int	un;
	int				i;
	char			buffer[100];

	if (n == 0)
	{
		write (1, "0", 1);
	}
	else
	{
		if (n < 0)
			write (1, "-", 1);
		un = ft_signed_to_positive (n);
		i = 0;
		while (un > 0)
		{
			buffer[99 - i] = '0' + (un % 10);
			un /= 10;
			i += 1;
		}
		write (1, &buffer[100 - i], i);
	}
}
