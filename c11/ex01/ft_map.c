/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 04:47:55 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/10 04:49:19 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int	*result;
	int	i;

	result = malloc (sizeof (int) * length);
	i = 0;
	while (i < length)
	{
		result[i] = f (tab[i]);
		i += 1;
	}
	return (result);
}
