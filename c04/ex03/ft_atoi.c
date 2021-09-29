/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:52:54 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/05 11:39:11 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int				digits;
	int				sign;
	unsigned int	un;
	int				exp;

	while (*str && ft_isspace (*str))
		str += 1;
	sign = 1;
	while (*str && (*str == '+' || *str == '-'))
	{
		sign *= (*str == '+') * 2 - 1;
		str += 1;
	}
	digits = 0;
	while (str[digits] && ft_isdigit (str[digits]))
		digits += 1;
	un = 0;
	exp = 1;
	while (digits > 0)
	{
		un += exp * (str[digits - 1] - '0');
		exp *= 10;
		digits -= 1;
	}
	return (sign * un);
}
