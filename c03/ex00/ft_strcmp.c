/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:56:22 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/04 14:02:24 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	else if (n > 0)
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1 += 1;
		s2 += 1;
	}
	return (ft_sign (*s1 - *s2));
}
