/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:00:51 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/13 18:54:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>

char	*g_program_name = NULL;

void	ft_print(char *str)
{
	write (1, str, ft_strlen (str));
}

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

void	ft_print_usage(void)
{
	write (1, "usage: ", ft_strlen ("usage: "));
	write (1, g_program_name, ft_strlen (g_program_name));
	write (1, " -c # [file ...]\n", ft_strlen (" -c # [file ...]\n"));
}
