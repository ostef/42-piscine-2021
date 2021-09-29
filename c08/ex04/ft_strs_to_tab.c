/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:41:21 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/09 15:08:30 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*result;

	result = malloc (ft_strlen (str) + 1);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i += 1;
	}
	result[i] = 0;
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*result;
	int					i;

	if (!av)
		return (NULL);
	result = malloc (sizeof (struct s_stock_str) * (ac + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen (av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup (av[i]);
		i += 1;
	}
	result[i].size = 0;
	result[i].str = NULL;
	result[i].copy = NULL;
	return (result);
}
