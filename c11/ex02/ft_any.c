/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 04:52:07 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/10 04:53:42 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f) (char *))
{
	while (tab && *tab)
	{
		if (f (*tab))
			return (1);
		tab += 1;
	}
	return (0);
}
