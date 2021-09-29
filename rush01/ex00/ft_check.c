/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:44:04 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/12 21:33:29 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

static t_ui	ft_get_number(t_board *board, t_side side, t_ui i, t_ui j)
{
	if (side == SIDE_UP)
		return (board->numbers[i][j]);
	else if (side == SIDE_DOWN)
		return (board->numbers[i][BOARD_SIZE - j - 1]);
	else if (side == SIDE_LEFT)
		return (board->numbers[j][i]);
	else if (side == SIDE_RIGHT)
		return (board->numbers[BOARD_SIZE - j - 1][i]);
	return (0);
}

static int	ft_check_side(t_board *board, t_side side)
{
	t_ui	i;
	t_ui	j;
	t_ui	highest;
	t_ui	seeing;

	i = 0;
	while (i < BOARD_SIZE)
	{
		seeing = 0;
		highest = 0;
		j = 0;
		while (j < BOARD_SIZE)
		{
			if (ft_get_number (board, side, i, j) > highest)
			{
				highest = ft_get_number (board, side, i, j);
				seeing += 1;
			}
			j += 1;
		}
		if (seeing != board->sides[side][i])
			return (0);
		i += 1;
	}
	return (1);
}

t_ui	ft_check_board(t_board *board)
{
	t_side	side;

	side = SIDE_UP;
	while (side < SIDE_COUNT)
	{
		if (!ft_check_side (board, side))
			return (0);
		side += 1;
	}
	return (1);
}

static t_ui	ft_sudoku_check_col(t_board *board, t_ui col)
{
	t_ui	row;
	t_ui	i;
	t_ui	digits[BOARD_SIZE];

	row = 0;
	while (row < BOARD_SIZE)
	{
		i = 0;
		while (i < row)
		{
			if (board->numbers[col][row] == digits[i])
				return (0);
			i += 1;
		}
		digits[row] = board->numbers[col][row];
		row += 1;
	}
	return (1);
}

t_ui	ft_sudoku_check(t_board *board)
{
	t_ui	col;

	col = 0;
	while (col < BOARD_SIZE)
	{
		if (!ft_sudoku_check_col(board, col))
			return (0);
		col += 1;
	}
	return (1);
}
