/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:46:22 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/07 14:47:07 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:30:34 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/07 14:45:59 by soumanso         ###   ########lyon.fr   */
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

int	ft_strcpy_part(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	return (i);
}

int	calculate_total_size(int size, char **strs, char *sep)
{
	int	total_size;
	int	i;

	i = 0;
	total_size = 0;
	while (i < size)
	{
		total_size += ft_strlen (strs[i]);
		if (i < size - 1)
			total_size += ft_strlen (sep);
		i += 1;
	}
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_size;
	int		i;
	char	*buffer;
	char	*curr;

	total_size = calculate_total_size (size, strs, sep);
	buffer = malloc (total_size + 1);
	curr = buffer;
	i = 0;
	while (i < size)
	{
		curr += ft_strcpy_part (curr, strs[i]);
		if (i != size - 1)
			curr += ft_strcpy_part (curr, sep);
		i += 1;
	}
	*curr = 0;
	return (buffer);
}
