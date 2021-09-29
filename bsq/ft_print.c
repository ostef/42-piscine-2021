/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:10:33 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 02:00:15 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_print_char(char c)
{
	write (1, &c, 1);
}

void	ft_print_map(t_map *map)
{
	int		x;
	int		y;
	t_cell	cell;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			cell = ft_get_cell (map, x, y);
			if (cell == CELL_EMPTY)
				ft_print_char (map->empty);
			else if (cell == CELL_OBSTACLE)
				ft_print_char (map->obst);
			else if (cell == CELL_FILLED)
				ft_print_char (map->fill);
			x += 1;
		}
		ft_print_char ('\n');
		y += 1;
	}
}
