/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:27:34 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/06 12:29:36 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

int	main(int arg_count, char **args)
{
	int	i;

	i = arg_count - 1;
	while (i > 0)
	{
		write (1, args[i], ft_strlen (args[i]));
		write (1, "\n", 1);
		i -= 1;
	}
}
