/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:23:45 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/20 04:06:10 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

t_error	ft_parse_number(char **str, t_uint *nbr)
{
	t_error	err;

	err = ft_is_valid_uint (*str);
	if (err == NOT_AN_UINT)
		return (err);
	*nbr = 0;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		*str += 1;
	while (**str >= '0' && **str <= '9')
	{
		*nbr = *nbr * 10 + **str - '0';
		*str += 1;
	}
	return (err);
}

static void	ft_null_terminate(char *str, int i)
{
	while (str[i - 1] == ' ')
		i -= 1;
	str[i] = 0;
}

static char	*ft_read_value(char **line)
{
	char	*str;
	char	*start;
	int		i;
	int		j;

	start = *line;
	while (**line != '\n' && **line)
		*line += 1;
	str = malloc ((int)(*line - start) + 1);
	i = 0;
	j = 0;
	while (j < (int)(*line - start))
	{
		str[i] = start[j];
		if (start[j] == ' ')
		{
			while (start[j] == ' ')
				j += 1;
		}
		else
			j += 1;
		i += 1;
	}
	ft_null_terminate (str, i);
	return (str);
}

static t_bool	ft_parse_line(char **line, t_dict *dict)
{
	t_uint	nbr;
	char	*str;
	t_error	err;

	err = ft_parse_number (line, &nbr);
	if (err == NOT_AN_UINT)
		return (FALSE);
	while (**line == ' ')
		*line += 1;
	if (**line != ':')
		return (FALSE);
	*line += 1;
	while (**line == ' ')
		*line += 1;
	str = ft_read_value (line);
	if (!str)
		return (FALSE);
	*line += 1;
	if (err == SUCCESS || err == TRAILING_NON_DIGITS)
		ft_add_to_dict (dict, nbr, str);
	else
		free (str);
	return (TRUE);
}

t_bool	ft_parse_dict(char *str, t_dict *dict)
{
	while (*str)
	{
		while (*str == '\n')
			str += 1;
		if (!ft_parse_line (&str, dict))
			return (FALSE);
	}
	ft_sort_dict (dict);
	return (TRUE);
}
