/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:07:14 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/02 13:25:00 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	ft_charupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('A' + c - 'a');
	return (c);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_charupcase(str[i]);
		i += 1;
	}
	return (str);
}
