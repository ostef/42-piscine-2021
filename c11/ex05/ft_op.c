/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:12:02 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/13 02:35:56 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_add(int a, int b)
{
	ft_print_number (a + b);
	ft_print ("\n");
}

void	ft_sub(int a, int b)
{
	ft_print_number (a - b);
	ft_print ("\n");
}

void	ft_mul(int a, int b)
{
	ft_print_number (a * b);
	ft_print ("\n");
}

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_print ("Stop : division by zero\n");
		return ;
	}
	ft_print_number (a / b);
	ft_print ("\n");
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_print ("Stop : modulo by zero\n");
		return ;
	}
	ft_print_number (a % b);
	ft_print ("\n");
}
