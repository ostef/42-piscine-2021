/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:00:28 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/06 18:02:40 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*buffer;
	int		i;

	len = ft_strlen (src);
	buffer = malloc (len + 1);
	i = 0;
	while (i <= len)
	{
		buffer[i] = src[i];
		i += 1;
	}
	return (buffer);
}
