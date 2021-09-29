/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:14:53 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/22 01:58:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_error
{
	SUCCESS = 0
}	t_error;

typedef enum e_cell
{
	CELL_EMPTY = 0,
	CELL_OBSTACLE = 1,
	CELL_FILLED = 2
}	t_cell;

typedef struct s_map
{
	int		width;
	int		height;
	t_cell	*data;
	char	empty;
	char	obst;
	char	fill;
}	t_map;

typedef struct s_rect
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_rect;

t_rect	ft_rect(int x1, int y1, int x2, int y2);
int		ft_rect_width(t_rect rect);
int		ft_rect_height(t_rect rect);
t_bool	ft_is_printable(char c);
void	ft_print_char(char c);
void	ft_init_map(t_map *map);
void	ft_free_map(t_map *map);
t_bool	ft_parse_map(char *str, t_map *map);
t_cell	ft_get_cell(t_map *map, int x, int y);
void	ft_set_cell(t_map *map, int x, int y, t_cell cell);
void	ft_print_map(t_map *map);
void	ft_fill_region(t_map *map, t_rect rect);
t_rect	ft_find_largest_square(t_map *map);
int		ft_get_file_size(char *filename);
char	*ft_read_file(char *filename);

#endif
