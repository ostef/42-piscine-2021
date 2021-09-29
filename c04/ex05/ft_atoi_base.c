/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 00:39:35 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/07 12:31:57 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '\r')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	return (0);
}

int	ft_to_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i += 1;
	}
	return (-1);
}

int	ft_base_is_valid(char *base, int *base_len)
{
	int	i;
	int	j;

	if (!base || !base_len)
		return (0);
	i = 0;
	while (base[i])
	{
		if (ft_isspace (base[i]) || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j += 1;
		}
		i += 1;
	}
	if (i < 2)
		return (0);
	*base_len = i;
	return (1);
}

int	ft_calc_digits(char *str, char *base, unsigned int *un, int *exp)
{
	int	digits;

	*un = 0;
	*exp = 1;
	digits = 0;
	while (str[digits] && ft_to_digit (str[digits], base) != -1)
		digits += 1;
	return (digits);
}

int	ft_atoi_base(char *str, char *base)
{
	int				digits;
	int				sign;
	unsigned int	un;
	int				exp;
	int				base_len;

	if (!ft_base_is_valid (base, &base_len))
		return (0);
	while (*str && ft_isspace (*str))
		str += 1;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		sign *= (*str == '+') * 2 - 1;
		str += 1;
	}
	digits = ft_calc_digits (str, base, &un, &exp);
	while (digits > 0)
	{
		un += exp * ft_to_digit (str[digits - 1], base);
		exp *= base_len;
		digits -= 1;
	}
	return (sign * un);
}
