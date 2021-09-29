/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 00:00:18 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/20 18:32:03 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define HEX "0123456789abcdef"

char	*g_program_name = NULL;

void	ft_print_errno(void)
{
	write (2, g_program_name, ft_strlen (g_program_name));
	write (2, ": ", 2);
	write (2, strerror (errno), ft_strlen (strerror (errno)));
	write (2, "\n", 1);
}

void	ft_print_file_errno(char *filename)
{
	write (2, g_program_name, ft_strlen (g_program_name));
	write (2, ": ", 2);
	write (2, filename, ft_strlen (filename));
	write (2, ": ", 2);
	write (2, strerror (errno), ft_strlen (strerror (errno)));
	write (2, "\n", 1);
}

void	ft_print_error(char *errstr, char *arg)
{
	write (2, g_program_name, ft_strlen (g_program_name));
	write (2, ": ", 2);
	write (2, errstr, ft_strlen (errstr));
	if (arg)
	{
		write (2, " -- ", 4);
		write (2, arg, ft_strlen (arg));
	}
	write (2, "\n", 1);
}

void	ft_print_hex(unsigned long n, int digits)
{
	char	buffer[16];
	int		i;

	i = 0;
	while (n > 0 && i < digits)
	{
		buffer[15 - i] = HEX[n % 16];
		n /= 16;
		i += 1;
	}
	while (i < digits)
	{
		buffer[15 - i] = HEX[0];
		i += 1;
	}
	write (1, &buffer[16 - i], i);
}
