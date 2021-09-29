/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:37:37 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/12 21:38:28 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"
#include <unistd.h>

void	ft_print_board(t_board *board)
{
	t_ui	row;
	t_ui	col;
	char	c;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			c = board->numbers[col][row] + '0';
			write (1, &c, 1);
			if (col != BOARD_SIZE - 1)
				write (1, " ", 1);
			col += 1;
		}
		write (1, "\n", 1);
		row += 1;
	}
}

int	ft_parse(char *str, t_board *board)
{
	int		i;
	int		j;
	t_side	side;

	i = -1;
	j = 0;
	side = 0;
	while (str[++i])
		if ((i % 2) && str[i] != ' ')
			return (0);
	else if (i % 2 == 0)
	{
		if (str[i] < '1' || str[i] > '0' + BOARD_SIZE)
			return (0);
		if (j >= BOARD_SIZE)
		{
			if (side == SIDE_COUNT)
				return (0);
			side += 1;
			j = 0;
		}
		board->sides[side][j] = str[i] - '0';
		j += 1;
	}
	return (i == SIDE_COUNT * BOARD_SIZE * 2 - 1);
}

int	main(int argc, char **argv)
{
	t_board			board;

	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	if (!ft_parse(argv[1], &board))
	{
		write (1, "Error\n", 6);
		return (1);
	}
	if (!ft_solve (&board))
	{
		write (1, "Error\n", 6);
		return (1);
	}
}
