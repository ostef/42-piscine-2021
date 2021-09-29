/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:25:18 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/06 12:27:11 by soumanso         ###   ########lyon.fr   */
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

	i = 1;
	while (i < arg_count)
	{
		write (1, args[i], ft_strlen (args[i]));
		write (1, "\n", 1);
		i += 1;
	}
}
