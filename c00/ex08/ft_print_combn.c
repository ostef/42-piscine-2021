/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:35:52 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/02 02:49:37 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i += 1;
	}
	return (dest);
}

int	ft_is_last_number(char *buffer, int length)
{
	int	i;
	int	max_digit;

	i = 0;
	while (i < length)
	{
		max_digit = 10 - (length - i);
		if (buffer[i] - '0' != max_digit)
			return (0);
		i += 1;
	}
	return (1);
}

void	ft_print_helper(int start, int n, char *prev_buff, int prev_len)
{
	int		i;
	char	buffer[10];
	int		length;

	if (n == 0)
	{
		write(1, prev_buff, prev_len);
		if (!ft_is_last_number(prev_buff, prev_len))
			write(1, ", ", 2);
	}
	else
	{
		i = start;
		while (i <= 9)
		{
			if (prev_buff != 0)
			{
				ft_memcpy (buffer, prev_buff, prev_len);
			}
			buffer[prev_len] = '0' + i;
			length = prev_len + 1;
			ft_print_helper(i + 1, n - 1, buffer, length);
			i += 1;
		}
	}
}

void	ft_print_combn(int n)
{
	if (n > 0 && n < 10)
	{
		ft_print_helper(0, n, 0, 0);
	}
}
