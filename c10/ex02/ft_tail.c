/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:03:59 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 19:40:46 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>

#define BUFFER_SIZE 25000

int	ft_read_entire_file(int fd, char **buffer)
{
	char	*prev_buffer;
	int		len;
	int		size;
	int		capacity;

	size = 0;
	capacity = 1024;
	prev_buffer = NULL;
	*buffer = NULL;
	while (1)
	{
		if (*buffer)
		{
			free (prev_buffer);
			prev_buffer = *buffer;
		}
		*buffer = malloc (capacity);
		ft_memcpy (*buffer, prev_buffer, size);
		len = read (fd, *buffer + size, capacity - size);
		if (len == 0)
			break ;
		size += len;
		capacity *= 2;
	}
	return (size);
}

void	ft_redirection(int c)
{
	char	*buffer;
	int		len;

	if (c <= 10)
		return ;
	len = ft_read_entire_file (0, &buffer);
	if (len)
		write (1, buffer + len - ft_min (len, c), ft_min (len, c));
}

int	ft_read_and_print_file(char *filename, int c, int print_nl, int file_count)
{
	char	*buffer;
	int		len;
	int		fd;

	fd = open (filename, O_RDONLY);
	if (fd == -1)
	{
		ft_print_file_errno (filename);
		return (0);
	}
	len = ft_read_entire_file(fd, &buffer);
	close (fd);
	if (len > 0)
	{
		if (print_nl > 0)
			write (1, "\n", 1);
		if (file_count > 1)
		{
			ft_print ("==> ");
			ft_print (filename);
			ft_print (" <==\n");
		}
		write (1, buffer + len - ft_min (len, c), ft_min (len, c));
	}
	return (len != -1);
}

int	main(int arg_count, char **args)
{
	int	c;
	int	i;
	int	res;

	g_program_name = basename (args[0]);
	if (arg_count < 3)
	{
		ft_print_error ("option requires an argument", "c");
		return (1);
	}
	if (!ft_atoiv (args[2], &c))
	{
		ft_print_error ("illegal offset", args[2]);
		return (1);
	}
	if (arg_count == 3)
		ft_redirection (c);
	i = 3;
	res = 0;
	while (i < arg_count)
	{
		res += ft_read_and_print_file (args[i], c, res, arg_count - 3);
		i += 1;
	}
	return (0);
}
