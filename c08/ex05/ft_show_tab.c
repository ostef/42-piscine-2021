/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:53:26 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/09 15:08:09 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

unsigned int	ft_signed_to_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr(int n)
{
	char			buffer[10];
	int				i;
	unsigned int	un;

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
			buffer[99 - i] = (un % 10) + '0';
			un /= 10;
			i += 1;
		}
		write (1, &buffer[100 - i], i);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par && par->str)
	{
		write (1, par->str, ft_strlen (par->str));
		write (1, "\n", 1);
		ft_putnbr (par->size);
		write (1, "\n", 1);
		write (1, par->copy, ft_strlen (par->copy));
		write (1, "\n", 1);
		par += 1;
	}
}
