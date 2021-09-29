/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 05:01:53 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/15 19:06:44 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sorted_ascending(int *tab, int length, int (*f) (int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f (tab[i], tab[i + 1]) > 0)
			return (0);
		i += 1;
	}
	return (1);
}

int	ft_is_sorted_descending(int *tab, int length, int (*f) (int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f (tab[i], tab[i + 1]) < 0)
			return (0);
		i += 1;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	if (ft_is_sorted_ascending (tab, length, f))
		return (1);
	if (ft_is_sorted_descending (tab, length, f))
		return (1);
	return (0);
}
