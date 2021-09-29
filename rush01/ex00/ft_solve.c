/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:24:30 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/13 22:44:10 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

static void	ft_swap(t_ui *a, t_ui *b)
{
	t_ui	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <stdio.h>

static void	ft_print_help(t_board *board, t_ui row, t_ui col1, t_ui col2)
{
	int	row_i;
	int	col_i;

	printf ("\n");
	printf (" ");
	for (int i = 0; i < (int)col1; i += 1)
		printf (" ");
	printf ("a\n");
	printf (" ");
	for (int i = 0; i < (int)col2; i += 1)
		printf (" ");
	printf ("b\n");
	row_i = 0;
	while (row_i < BOARD_SIZE)
	{
		if (row_i == (int)row)
			printf (">");
		else
			printf (" ");
		col_i = 0;
		while (col_i < BOARD_SIZE)
		{
			printf ("%d", board->numbers[col_i][row_i]);
			if (col_i != BOARD_SIZE - 1)
				printf (" ");
			col_i += 1;
		}
		if (row_i == (int)row)
			printf ("<");
		printf ("\n");
		row_i += 1;
	}
	printf ("\n");
}

static t_ui	ft_permute(t_board *board, t_ui row, t_ui col)
{
	t_ui	i;

	if (row == BOARD_SIZE)
	{
		printf ("Checking board...\n");
		ft_print_help (board, row, col, col);
		if (ft_sudoku_check (board) && ft_check_board (board))
		{
			ft_print_board (board);
			printf ("       OK!\n");
			return (1);
		}
		printf ("     Not a solution.\n");
		return (0);
	}
	else
	{
		i = col;
		while (i < BOARD_SIZE)
		{
			ft_swap (&board->numbers[col][row], &board->numbers[i][row]);
			ft_print_help (board, row, col, i);
			if (ft_permute (board, row, col + 1))
				return (1);
			if (ft_permute (board, row + 1, 0))
				return (1);
			ft_swap (&board->numbers[col][row], &board->numbers[i++][row]);
		}
	}
	return (0);
}

t_ui	ft_solve(t_board *board)
{
	int	col;
	int	row;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			board->numbers[col][row] = ((col + row) % BOARD_SIZE) + 1;
			col += 1;
		}
		row += 1;
	}
	return (ft_permute (board, 0, 0));
}
