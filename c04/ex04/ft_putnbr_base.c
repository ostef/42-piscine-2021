/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:24:02 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/05 11:07:14 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_base_valid(char *base, int *base_len)
{
	int	i;
	int	j;

	if (!base || !base_len)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j += 1;
		}
		i += 1;
	}
	if (i < 2)
		return (0);
	*base_len = i;
	return (1);
}

unsigned int	ft_signed_to_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	unsigned int	un;
	char			buffer[100];
	int				i;

	if (!ft_is_base_valid (base, &base_len))
		return ;
	if (nbr == 0)
	{
		write (1, base, 1);
	}
	else
	{
		if (nbr < 0)
			write (1, "-", 1);
		un = ft_signed_to_positive(nbr);
		i = 0;
		while (un > 0)
		{
			buffer[99 - i] = base[un % base_len];
			un /= base_len;
			i += 1;
		}
		write (1, &buffer[100 - i], i);
	}
}
