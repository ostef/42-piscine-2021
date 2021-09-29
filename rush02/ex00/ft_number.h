/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:48:46 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/19 23:34:50 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBER_H
# define FT_NUMBER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef unsigned int	t_uint;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_error
{
	SUCCESS = 0,
	ERROR = 1,
	DICT_ERROR = 2,
	UINT_TOO_BIG = 3,
	NOT_AN_UINT = 4,
	TRAILING_NON_DIGITS = 5
}	t_error;

typedef struct s_dict_entry
{
	t_uint	nbr;
	char	*str;
}	t_dict_entry;

typedef struct s_dict
{
	t_dict_entry	*data;
	int				count;
	int				capacity;
}	t_dict;

t_dict	ft_make_dict(int n);
void	ft_free_dict(t_dict *dict);
void	ft_grow_dict(t_dict *dict);
void	ft_add_to_dict(t_dict *dict, t_uint nbr, char *str);
char	*ft_dict_get(t_dict *dict, t_uint nbr);
void	ft_sort_dict(t_dict *t_dict);
t_bool	ft_parse_dict(char *str, t_dict *dict);
char	*ft_read_file(char *filename);
t_error	ft_parse_number(char **str, t_uint *nbr);
void	ft_print_written_number(t_uint nbr, t_dict *dict, char *end);
void	ft_print(char *str);
t_error	ft_is_valid_uint(char *str);

#endif
