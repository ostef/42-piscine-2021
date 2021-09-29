/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:39:52 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/13 22:25:28 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SKYSCRAPER_H
# define FT_SKYSCRAPER_H

# include <stdlib.h>

# ifdef BOARD_SIZE
#  error "Do not define BOARD_SZE."
# else
#  define BOARD_SIZE 4
# endif

# define BASE "0123456789"

typedef unsigned int	t_ui;

typedef enum e_side
{
	SIDE_UP = 0,
	SIDE_DOWN = 1,
	SIDE_LEFT = 2,
	SIDE_RIGHT = 3,
	SIDE_COUNT = 4
}						t_side;

typedef struct s_board
{
	union
	{
		struct
		{
			t_ui		up[BOARD_SIZE];
			t_ui		down[BOARD_SIZE];
			t_ui		left[BOARD_SIZE];
			t_ui		right[BOARD_SIZE];
		};
		t_ui			sides[SIDE_COUNT][BOARD_SIZE];
	};
	t_ui				numbers[BOARD_SIZE][BOARD_SIZE];
}						t_board;

void					*ft_memcpy(void *dest, void *src, t_ui n);
void					ft_print_board(t_board *board);
t_ui					ft_sudoku_check(t_board *board);
t_ui					ft_check_board(t_board *board);
t_ui					ft_solve(t_board *board);
#endif
