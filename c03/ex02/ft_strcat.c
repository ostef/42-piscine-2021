/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:05:27 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/03 21:09:13 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	dest_len;
	char			*curr;
	unsigned int	i;

	dest_len = ft_strlen (dest);
	curr = dest + dest_len;
	i = 0;
	while (src[i])
	{
		curr[i] = src[i];
		i += 1;
	}
	curr[i] = 0;
	return (dest);
}
