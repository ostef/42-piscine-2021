/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:22:35 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/07 11:50:24 by soumanso         ###   ########lyon.fr   */
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
	if (arg_count > 0)
	{
		write (1, args[0], ft_strlen (args[0]));
		write (1, "\n", 1);
	}
	return (0);
}
