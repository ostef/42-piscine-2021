/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:19:26 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/09 23:39:28 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

unsigned int	min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	copied;

	if (size == 0)
		return (ft_strlen (src));
	dest_len = ft_strlen (dest);
	i = 0;
	copied = 0;
	while (src[i])
	{
		if (dest_len + i < size - 1)
		{
			dest[dest_len + i] = src[i];
			copied += 1;
		}
		i += 1;
	}
	dest[dest_len + copied] = 0;
	return (min (dest_len, size) + i);
}
