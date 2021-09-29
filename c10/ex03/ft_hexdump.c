/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:36:53 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 19:54:59 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>

void	ft_dump_bytes(t_file_reader *reader, int len, int ascii)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		write (1, " ", 1);
		if (j < len)
			ft_print_hex ((unsigned long)reader->curr_line[j], 2);
		else
			write (1, "  ", 2);
		j += 1;
	}
	if (ascii)
		write (1, " ", 1);
	while (j < 16)
	{
		write (1, " ", 1);
		if (j < len)
			ft_print_hex ((unsigned long)reader->curr_line[j], 2);
		else
			write (1, "  ", 2);
		j += 1;
	}
}

void	ft_dump_ascii(t_file_reader *reader, int len)
{
	int	j;

	write (1, "  |", 3);
	j = 0;
	while (j < len)
	{
		if (reader->curr_line[j] < 32 || reader->curr_line[j] > 126)
			write (1, ".", 1);
		else
			write (1, reader->curr_line + j, 1);
		j += 1;
	}
	write (1, "|", 1);
}

void	ft_dump(t_file_reader *reader, int i, int len, int ascii)
{
	if (len == 16
		&& ft_memcmp (reader->prev_line, reader->curr_line, 16) == 0)
	{
		if (!reader->same_line)
			write (1, "*\n", 2);
		reader->same_line = 1;
	}
	else
	{
		reader->same_line = 0;
		ft_print_hex (i, 7 + ascii);
		if (ascii)
			write (1, " ", 1);
		ft_dump_bytes (reader, len, ascii);
		if (ascii)
			ft_dump_ascii (reader, len);
		write (1, "\n", 1);
	}
}

void	ft_dump_files(char **files, int count, int ascii)
{
	t_file_reader	reader;
	int				i;
	int				len;

	ft_init_reader (&reader, files, count);
	i = 0;
	while (1)
	{
		len = ft_read_next_block (&reader);
		if (len <= 0)
			break ;
		ft_dump (&reader, i, len, ascii);
		i += len;
	}
	if (i != 0)
	{
		ft_print_hex (i, 7 + ascii);
		write (1, "\n", 1);
	}
}

int	main(int arg_count, char **args)
{
	int	ascii;

	g_program_name = basename (args[0]);
	ascii = arg_count >= 2 && ft_strcmp (args[1], "-C") == 0;
	if (ascii)
	{
		args += 2;
		arg_count -= 2;
	}
	else
	{
		args += 1;
		arg_count -= 1;
	}
	ft_dump_files (args, arg_count, ascii);
	return (0);
}
