/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:46:01 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/19 22:01:48 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

static int	ft_get_file_size(char *filename)
{
	int		fd;
	int		len;
	int		total_len;
	char	c;

	fd = open (filename, O_RDONLY);
	if (fd == -1)
		return (0);
	total_len = 0;
	while (1)
	{
		len = read (fd, &c, 1);
		if (len <= 0)
			break ;
		total_len += 1;
	}
	close (fd);
	return (total_len);
}

char	*ft_read_file(char *filename)
{
	int		fd;
	int		len;
	char	*buffer;

	len = ft_get_file_size (filename);
	if (len == 0)
		return (NULL);
	buffer = malloc (len + 1);
	if (!buffer)
		return (NULL);
	fd = open (filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read (fd, buffer, len);
	close (fd);
	buffer[len] = 0;
	return (buffer);
}
