/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:30:01 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/06 12:38:14 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1 += 1;
		s2 += 1;
	}
	return (*s1 - *s2);
}

int	main(int arg_count, char **args)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < arg_count - 1)
	{
		if (ft_strcmp (args[i], args[i + 1]) > 0)
		{
			temp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = temp;
			i = 1;
		}
		else
		{
			i += 1;
		}
	}
	i = 1;
	while (i < arg_count)
	{
		write (1, args[i], ft_strlen (args[i]));
		write (1, "\n", 1);
		i += 1;
	}
}
