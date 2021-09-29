/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:26:36 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/10 04:30:01 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned long n, int digits)
{
	char	buffer[16];
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (n > 0 && i < digits)
	{
		buffer[15 - i] = hex_digits[n % 16];
		n /= 16;
		i += 1;
	}
	while (i < digits)
	{
		buffer[15 - i] = hex_digits[0];
		i += 1;
	}
	write (1, &buffer[16 - i], i);
}

void	ft_print_middle(char *as_str, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		write (1, " ", 1);
		if (i + j < size)
			ft_print_hex ((unsigned long)as_str[j], 2);
		else
			write (1, "  ", 2);
		j += 1;
		if (i + j < size)
			ft_print_hex ((unsigned long)as_str[j], 2);
		else
			write (1, "  ", 2);
		j += 1;
	}
}

void	ft_print_str(char *str, unsigned int size)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < 16 && i < size)
	{
		if (str[i] < ' ' || str [i] > 126)
			c = '.';
		else
			c = str[i];
		write (1, &c, 1);
		i += 1;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*as_str;

	i = 0;
	while (i < size)
	{
		ft_print_hex ((unsigned long)(addr + i), 16);
		as_str = (char *)addr + i;
		write (1, ":", 1);
		ft_print_middle (as_str, i, size);
		write (1, " ", 1);
		ft_print_str (as_str, size - i);
		write (1, "\n", 1);
		i += 16;
	}
	return (addr);
}
