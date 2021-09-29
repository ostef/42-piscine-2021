/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:07:22 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/06 12:21:19 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_is_ok(int *queens, int i)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = 0;
	while (x1 <= i)
	{
		y1 = queens[x1];
		x2 = x1 + 1;
		while (x2 <= i)
		{
			y2 = queens[x2];
			if (y2 == y1 + (x2 - x1))
				return (0);
			else if (y2 == y1)
				return (0);
			else if (y2 == y1 - (x2 - x1))
				return (0);
			x2 += 1;
		}
		x1 += 1;
	}
	return (1);
}

void	ft_display_queens(int *queens)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write (1, &c, 1);
		i += 1;
	}
	write (1, "\n", 1);
}

int	ft_compute(int *queens, int i)
{
	int	j;
	int	solutions;

	if (i == 10)
	{
		ft_display_queens (queens);
		return (1);
	}
	solutions = 0;
	j = 0;
	while (j < 10)
	{
		queens[i] = j;
		if (ft_is_ok (queens, i))
			solutions += ft_compute (queens, i + 1);
		j += 1;
	}
	return (solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];

	return (ft_compute (queens, 0));
}
