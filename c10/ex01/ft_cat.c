/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:59:46 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/15 14:08:14 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define BUFFER_SIZE 25000

char	*g_program_name = NULL;

void	ft_input_loop(void)
{
	char	buffer[BUFFER_SIZE];
	int		len;

	while (1)
	{
		len = read (0, buffer, BUFFER_SIZE);
		if (len == 0)
			break ;
		write (1, buffer, len);
	}
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

void	ft_read_and_print_file(char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		len;

	fd = open (filename, O_RDONLY);
	if (fd == -1)
	{
		ft_print_file_errno (filename);
		return ;
	}
	while (1)
	{
		len = read (fd, buffer, BUFFER_SIZE);
		write (1, buffer, len);
		if (len < BUFFER_SIZE)
			break ;
	}
	close (fd);
}

int	main(int arg_count, char **args)
{
	int		i;

	g_program_name = basename (args[0]);
	if (arg_count == 1)
	{
		ft_input_loop ();
	}
	else
	{
		i = 1;
		while (i < arg_count)
		{
			if (ft_strcmp (args[i], "-") == 0)
				ft_input_loop ();
			else
				ft_read_and_print_file (args[i]);
			i += 1;
		}
	}	
}
