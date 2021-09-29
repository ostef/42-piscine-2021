/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:48:30 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/23 13:02:08 by soumanso         ###   ########lyon.fr   */
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

int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i += 1;
	}
	return (0);
}

char	*ft_strndup(char *str, int n)
{
	char	*result;
	int		i;

	result = malloc (n + 1);
	i = 0;
	while (str[i] && i < n)
	{
		result[i] = str[i];
		i += 1;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**buffer;
	int		start;
	int		end;
	int		i;
	int		len;

	len = ft_strlen (str);
	buffer = malloc (sizeof (char *) * (len + 1));
	start = 0;
	end = 0;
	i = 0;
	while (end <= len)
	{
		if (str[end] == 0 || ft_find (charset, str[end]))
		{
			if (end > start)
			{
				buffer[i++] = ft_strndup (str + start, end - start);
			}
			start = end + 1;
		}
		end += 1;
	}
	buffer[i] = NULL;
	return (buffer);
}

#include <stdio.h>

int	main(int argc, char **args)
{
	char **result = ft_split (args[1], args[2]);
	for (int i = 0; result[i]; i += 1)
	{
		printf ("%s\n", result[i]);
	}
}
