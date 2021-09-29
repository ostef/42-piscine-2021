/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nziatt <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:18:25 by nziatt            #+#    #+#             */
/*   Updated: 2021/09/04 15:09:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int l, int c, int x, int y)
{
	if ((l == 0 && c == 0) || (l == y - 1 && c == x - 1))
		ft_putchar ('o');
	else if ((l == y - 1 && c == 0) || (l == 0 && c == x - 1))
		ft_putchar ('o');
	else if (l == 0 || l == y - 1)
		ft_putchar ('-');
	else if (c == 0 || c == x - 1)
		ft_putchar ('|');
	else
		ft_putchar (' ');
}

/*
 * rush (5, 3):
 * o---o
 * |   |
 * o---o
 */
void	rush(int x, int y)
{
	int	l;
	int	c;

	l = 0;
	while (l < y)
	{
		c = 0;
		while (c < x)
		{
			print_char (l, c, x, y);
			c++;
		}
		l++;
		ft_putchar ('\n');
	}	
}
