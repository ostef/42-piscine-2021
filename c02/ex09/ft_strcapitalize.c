/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:25:21 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/09 22:42:05 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	ft_charlowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ('a' + c - 'A');
	return (c);
}

char	ft_charupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('A' + c - 'a');
	return (c);
}

int	ft_is_alpha_num(char c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || !ft_is_alpha_num (str[i - 1]))
			str[i] = ft_charupcase(str[i]);
		else
			str[i] = ft_charlowcase(str[i]);
		i += 1;
	}
	return (str);
}
