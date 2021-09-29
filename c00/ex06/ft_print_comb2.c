/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:04:43 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/01 12:13:39 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_two_digit_number(int n)
{
	int	a;
	int	b;

	a = n % 10;
	n /= 10;
	b = n % 10;
	ft_putchar ('0' + b);
	ft_putchar ('0' + a);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_print_two_digit_number(i);
			ft_putchar(' ');
			ft_print_two_digit_number(j);
			if (i != 98)
			{
				write(1, ", ", 2);
			}
			j += 1;
		}
		i += 1;
	}
}
