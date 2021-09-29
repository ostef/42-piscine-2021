/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:58:24 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/21 17:59:16 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_get_file_size(char *filename)
{
	char	c;
	int		len;
	int		fd;

	fd = open (filename, O_RDONLY);
	if (fd == -1)
		return (0);
	len = 0;
	while (read (fd, &c, 1))
		len += 1;
	close (fd);
	return (len);
}

char	*ft_read_file(char *filename)
{
	char	*buffer;
	int		len;
	int		fd;

	len = ft_get_file_size (filename);
	if (!len)
		return (NULL);
	fd = open (filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = malloc (len + 1);
	read (fd, buffer, len);
	close (fd);
	buffer[len] = 0;
	return (buffer);
}
