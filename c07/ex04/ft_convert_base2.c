/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:10:49 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/07 15:58:22 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_base_is_valid(char *base, int *base_len);
int	ft_atoi_base(char *nbr, char *base);

unsigned int	ft_signed_to_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_calc_digits_in_int(int nbr, int base_len)
{
	int				digits;
	unsigned int	un;

	if (nbr == 0)
		return (1);
	un = ft_signed_to_positive (nbr);
	digits = 0;
	while (un > 0)
	{
		un /= base_len;
		digits += 1;
	}
	return (digits);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int				base_len;
	unsigned int	un;
	char			*buffer;
	int				len;
	int				i;

	if (!ft_base_is_valid (base, &base_len))
		return (NULL);
	len = ft_calc_digits_in_int (nbr, base_len) + (nbr < 0);
	buffer = malloc (len + 1);
	if (nbr < 0)
		buffer[0] = '-';
	un = ft_signed_to_positive (nbr);
	if (un == 0)
		buffer[0] = base[0];
	i = 0;
	while (un > 0)
	{
		buffer[len - 1 - i] = base[un % base_len];
		un /= base_len;
		i += 1;
	}
	buffer[len] = 0;
	return (buffer);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;

	n = ft_atoi_base(nbr, base_from);
	if (n == -1)
		return (NULL);
	return (ft_itoa_base (n, base_to));
}
