/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:10:32 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/06 18:14:05 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (!range)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc (sizeof (int) * (max - min));
	if (!(*range))
		return (-1);
	i = min;
	while (i < max)
	{
		(*range)[i - min] = i;
		i += 1;
	}
	return (max - min);
}
