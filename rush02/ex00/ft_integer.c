/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:53:36 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/19 23:39:21 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

static int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && i < n)
		i += 1;
	if (s1[i] == s2[i])
		return (0);
	return (s1[i] - s2[i]);
}

t_error	ft_is_valid_uint(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i += 1;
	if (i == 0)
		return (NOT_AN_UINT);
	if (i > 10)
		return (UINT_TOO_BIG);
	if (i < 10)
	{
		if (str[i] != 0)
			return (TRAILING_NON_DIGITS);
		return (SUCCESS);
	}
	if (ft_strncmp (str, "4294967295", i) > 0)
		return (UINT_TOO_BIG);
	if (str[i] != 0)
		return (TRAILING_NON_DIGITS);
	return (SUCCESS);
}
