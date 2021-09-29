/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:05:23 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/14 13:20:12 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define ERRSTR_FILE_NAME "File name missing.\n"
#define ERRSTR_ARGUMENTS "Too many arguments.\n"
#define ERRSTR_FILE "Cannot read file.\n"

#define SUCCESS 0
#define ERR_FILE_NAME 1
#define ERR_ARGUMENTS 2
#define ERR_FILE 3

#define BUFFER_SIZE 1024

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

void	ft_print_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		len;

	while (1)
	{
		len = read (fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			write (2, ERRSTR_FILE, ft_strlen (ERRSTR_FILE));
			break ;
		}
		write (1, buffer, len);
		if (len < BUFFER_SIZE)
			break ;
	}
}

int	main(int arg_count, char **args)
{
	int		fd;

	if (arg_count < 2)
	{
		write (2, ERRSTR_FILE_NAME, ft_strlen (ERRSTR_FILE_NAME));
		return (ERR_FILE_NAME);
	}
	else if (arg_count > 2)
	{
		write (2, ERRSTR_ARGUMENTS, ft_strlen (ERRSTR_ARGUMENTS));
		return (ERR_ARGUMENTS);
	}
	fd = open (args[1], O_RDONLY);
	if (fd == -1)
	{
		write (2, ERRSTR_FILE, ft_strlen (ERRSTR_FILE));
		return (ERR_FILE);
	}
	ft_print_file (fd);
	close (fd);
	return (SUCCESS);
}
