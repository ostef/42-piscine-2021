/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 00:10:29 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 20:24:39 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

void	ft_init_reader(t_file_reader *reader, char **files, int count)
{
	reader->files = files;
	reader->file_index = 0;
	reader->file_count = count;
	reader->same_line = 0;
	reader->valid_files = 0;
	if (reader->file_count == 0)
	{
		reader->fd = 0;
		reader->file_count = 1;
	}
	else
	{
		reader->file_index = -1;
		ft_next_file (reader);
	}
}

void	ft_next_file(t_file_reader *reader)
{
	reader->file_index += 1;
	if (reader->file_index >= reader->file_count)
	{
		if (reader->valid_files == 0 && reader->fd != 0)
		{
			errno = EBADF;
			ft_print_file_errno (reader->files[reader->file_count - 1]);
		}
		return ;
	}
	reader->fd = open (reader->files[reader->file_index], O_RDONLY);
	if (reader->fd < 0)
	{
		ft_print_file_errno (reader->files[reader->file_index]);
		ft_next_file (reader);
	}
	else
		reader->valid_files += 1;
}

int	ft_read_next_block(t_file_reader *reader)
{
	int	len;
	int	count;

	ft_memcpy (reader->prev_line, reader->curr_line, 16);
	len = 0;
	count = 0;
	while (count < 16 && reader->file_index < reader->file_count)
	{
		len = read (reader->fd, reader->curr_line + count, 16 - count);
		if (len < 16 - count)
			ft_next_file (reader);
		count += len;
	}
	return (count);
}
