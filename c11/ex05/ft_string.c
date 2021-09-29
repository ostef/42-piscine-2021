/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:21:51 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/13 19:28:16 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(char *str)
{
	unsigned int	un;
	int				sign;

	while (*str && ft_is_space (*str))
		str += 1;
	sign = 1;
	while (*str && (*str == '+' || *str == '-'))
	{
		str += 1;
		sign *= (*str == '+') * 2 - 1;
	}
	un = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		un *= 10;
		un += *str - '0';
		str += 1;
	}
	return (sign * un);
}
