/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:18:25 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 01:58:58 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

static t_bool	ft_parse_number(char **str, int *n)
{
	if (**str < '0' || **str > '9')
		return (FALSE);
	while (**str >= '0' && **str <= '9')
	{
		*n *= 10;
		*n += **str - '0';
		*str += 1;
	}
	return (TRUE);
}

static t_bool	ft_parse_printable(char **str, char *out)
{
	if (!ft_is_printable (**str))
		return (FALSE);
	*out = **str;
	*str += 1;
	return (TRUE);
}

static t_bool	ft_parse_first_line(char **str, t_map *map)
{
	if (!ft_parse_number (str, &map->height))
		return (FALSE);
	if (map->height == 0)
		return (FALSE);
	if (!ft_parse_printable (str, &map->empty_char))
		return (FALSE);
	if (!ft_parse_printable (str, &map->obstacle_char))
		return (FALSE);
	if (!ft_parse_printable (str, &map->filled_char))
		return (FALSE);
	if (map->empty_char == map->obstacle_char
		|| map->empty_char == map->filled_char
		|| map->obstacle_char == map->filled_char)
		return (FALSE);
	while (**str != '\n')
		*str += 1;
	*str += 1;
	return (TRUE);
}

static t_bool	ft_parse_line(char **str, t_map *map, int line)
{
	int		x;
	t_cell	cell;

	x = 0;
	while (**str && **str != '\n' && x < map->width)
	{
		if (**str == map->empty_char)
			cell = CELL_EMPTY;
		else if (**str == map->obstacle_char)
			cell = CELL_OBSTACLE;
		else if (**str == map->filled_char)
			cell = CELL_FILLED;
		else
			return (FALSE);
		ft_set_cell (map, x, line, cell);
		x += 1;
		*str += 1;
	}
	if (**str && **str != '\n')
		return (FALSE);
	*str += 1;
	if ((line == map->height - 1 && **str)
		|| x != map->width)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_parse_map(char *str, t_map *map)
{
	int		line;

	if (!ft_parse_first_line (&str, map))
		return (FALSE);
	map->width = 0;
	while (str[map->width] && str[map->width] != '\n')
		map->width += 1;
	if (map->width == 0)
		return (FALSE);
	map->data = malloc (sizeof (t_cell) * map->width * map->height);
	line = 0;
	while (line < map->height)
	{
		if (!ft_parse_line (&str, map, line))
			return (FALSE);
		line += 1;
	}
	return (TRUE);
}
