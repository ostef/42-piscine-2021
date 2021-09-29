/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:35:14 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 02:00:01 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <stdio.h>

static t_bool	ft_check_rect(t_map *map, t_rect rect)
{
	int	x;
	int	y;

	if (rect.x2 >= map->width || rect.y2 >= map->height)
		return (FALSE);
	x = rect.x1;
	while (x <= rect.x2)
	{
		y = rect.y1;
		while (y <= rect.y2)
		{
			if (ft_get_cell (map, x, y) != CELL_EMPTY)
				return (FALSE);
			y += 1;
		}
		x += 1;
	}
	return (TRUE);
}

static t_rect	ft_get_rect(t_map *map)
{
	t_rect	best_rect;
	t_rect	rect;

	best_rect = ft_rect (0, 0, 0, 0);
	rect = ft_rect (0, 0, 0, 0);
	while (rect.y1 < map->height)
	{
		while (1)
		{
			rect.x2 += 1;
			rect.y2 += 1;
			if (!ft_check_rect (map, rect))
			{
				rect.x2 -= 1;
				rect.y2 -= 1;
				break ;
			}
		}
		if (ft_rect_width (rect) > ft_rect_width (best_rect))
			best_rect = rect;
		rect.x1 += 1;
		if (rect.x1 == map->width)
		{
			rect.x1 = 0;
			rect.y1 += 1;
		}
		rect.x2 = rect.x1;
		rect.y2 = rect.y1;
	}
	return (best_rect);
}

void	ft_fill_rect(t_map *map, t_rect rect)
{
	int	x;
	int	y;

	if (rect.x1 >= rect.x2 || rect.y1 >= rect.y2)
		return ;
	x = rect.x1;
	while (x <= rect.x2)
	{
		y = rect.y1;
		while (y <= rect.y2)
		{
			ft_set_cell (map, x, y, CELL_FILLED);
			y += 1;
		}
		x += 1;
	}
}

#include <stdio.h>

int	main(int argc, char **args)
{
	t_map	map;
	char	*str;
	t_rect	rect;
	int		i;

	ft_init_map (&map);
	i = 1;
	while (i < argc)
	{
		str = ft_read_file (args[i]);
		if (!str)
		{
			write (1, "map error\n", 10);
			if (i < argc - 1)
				write (1, "\n", 1);
			ft_free_map (&map);
			i += 1;
			continue ;
		}
		if (!ft_parse_map (str, &map))
		{
			write (1, "map error\n", 10);
			if (i < argc - 1)
				write (1, "\n", 1);
			free (str);
			ft_free_map (&map);
			i += 1;
			continue ;
		}
		free (str);
		printf ("get_rect.\n");
		rect = ft_get_rect (&map);
		printf ("get_rect.\n");
		ft_fill_rect (&map, rect);
		ft_print_map (&map);
		if (i < argc - 1)
			write (1, "\n", 1);
		ft_free_map (&map);
		i += 1;
	}
}
