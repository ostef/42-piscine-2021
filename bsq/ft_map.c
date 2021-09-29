/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:14:53 by cben-bar          #+#    #+#             */
/*   Updated: 2021/09/22 01:59:20 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_free_map(t_map *map)
{
	free(map->data);
	map->width = 0;
	map->height = 0;
	map->data = 0;
	map->empty = 0;
	map->obst = 0;
	map->fill = 0;
}

void	ft_init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->data = 0;
	map->empty = 0;
	map->obst = 0;
	map->fill = 0;
}

t_cell	ft_get_cell(t_map *map, int x, int y)
{
	return (map->data[y * map->width + x]);
}

void	ft_set_cell(t_map *map, int x, int y, t_cell cell)
{
	map->data[y * map->width + x] = cell;
}
