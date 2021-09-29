/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:59:13 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/21 22:02:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoiv(char *str, int *result)
{
	int	digits;
	int	n;
	int	exp;

	if (!result)
		return (0);
	digits = 0;
	while (str[digits])
	{
		if (str[digits] < '0' || str[digits] > '9')
			return (0);
		digits += 1;
	}
	if (!digits)
		return (0);
	n = 0;
	exp = 1;
	while (digits > 0)
	{
		n += exp * (str[digits - 1] - '0');
		exp *= 10;
		digits -= 1;
	}
	*result = n;
	return (1);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
