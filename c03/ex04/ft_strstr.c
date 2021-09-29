/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:17:36 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/09 00:25:17 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strfind(char *str, char *with)
{
	int	i;

	i = 0;
	while (str[i] && with[i])
	{
		if (str[i] != with[i])
			return (0);
		i += 1;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	if (str == to_find || ft_strlen (to_find) == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		if (str == to_find || ft_strfind (str + i, to_find))
			return (str + i);
		i += 1;
	}
	return (0);
}
