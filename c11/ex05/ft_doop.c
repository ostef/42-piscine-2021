/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 05:13:21 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/13 02:35:51 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_op	ft_get_op(char c)
{
	if (c == '+')
		return (&ft_add);
	else if (c == '-')
		return (&ft_sub);
	else if (c == '*')
		return (&ft_mul);
	else if (c == '/')
		return (&ft_div);
	else if (c == '%')
		return (&ft_mod);
	return (0);
}

int	main(int arg_count, char **args)
{
	t_op	op;

	if (arg_count != 4)
		return (1);
	if (ft_strlen (args[2]) != 1)
	{
		ft_print ("0\n");
		return (0);
	}
	op = ft_get_op (*args[2]);
	if (op)
		op (ft_atoi (args[1]), ft_atoi (args[3]));
	else
		ft_print ("0\n");
	return (0);
}
