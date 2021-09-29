/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:03:19 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/02 15:20:49 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Copy up to size - 1 bytes from src to dest, and NULL terminate dest.
 * 
 * Returns the length of src. If size is 0, then dest is not used, so
 * ft_strlcpy can be called beforehand to allocate a big enough dest
 * buffer.
 */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	copied;

	i = 0;
	copied = 0;
	while (src[i])
	{
		if (size != 0 && i < size - 1)
		{
			dest[i] = src[i];
			copied += 1;
		}
		i += 1;
	}
	if (size != 0)
		dest[copied] = 0;
	return (i);
}
