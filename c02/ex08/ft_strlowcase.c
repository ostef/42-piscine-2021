/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:23:57 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/02 14:26:35 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	ft_charlowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ('a' + c - 'A');
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_charlowcase(str[i]);
		i += 1;
	}
	return (str);
}
