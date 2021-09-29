/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:35:45 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/20 04:05:27 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

static t_uint	ft_count_factor(t_uint *in, t_uint nbr)
{
	t_uint	factor;

	factor = 0;
	while (nbr <= *in)
	{
		factor += 1;
		*in -= nbr;
	}
	return (factor);
}

static void	ft_decompose_and_print(t_uint nbr, t_dict *dict)
{
	t_dict_entry	curr;
	t_uint			factor;
	int				i;

	i = dict->count - 1;
	while (i > 0)
	{
		curr = dict->data[i];
		factor = ft_count_factor (&nbr, curr.nbr);
		if (factor)
		{
			if (curr.nbr >= 100 || factor != 1)
				ft_print_written_number (factor, dict, " ");
			ft_print (curr.str);
			if (nbr != 0)
				ft_print (" ");
		}
		i -= 1;
	}
}

void	ft_print_written_number(t_uint nbr, t_dict *dict, char *end)
{
	if (nbr == 0)
		ft_print (dict->data[0].str);
	else
		ft_decompose_and_print (nbr, dict);
	ft_print (end);
}

static t_error	ft_init(char **args, int argc, t_dict *dict, t_uint *nbr)
{
	char	*dict_filename;
	char	*nbr_str;
	char	*dict_str;
	t_bool	dict_ok;

	if (argc < 1 || argc > 2)
		return (ERROR);
	dict_filename = "numbers.dict";
	if (argc == 2)
	{
		dict_filename = *args;
		args += 1;
	}
	nbr_str = *args;
	dict_str = ft_read_file (dict_filename);
	if (!dict_str)
		return (DICT_ERROR);
	dict_ok = ft_parse_dict (dict_str, dict);
	free (dict_str);
	if (!dict_ok)
		return (DICT_ERROR);
	if (ft_is_valid_uint (nbr_str) != SUCCESS)
		return (ERROR);
	ft_parse_number (&nbr_str, nbr);
	return (SUCCESS);
}

int	main(int argc, char **args)
{
	t_dict	dict;
	t_uint	nbr;
	t_error	err;

	dict = ft_make_dict (100);
	err = ft_init (args + 1, argc - 1, &dict, &nbr);
	if (err == DICT_ERROR)
		ft_print ("Dict Error\n");
	else if (err == ERROR)
		ft_print ("Error\n");
	else
		ft_print_written_number (nbr, &dict, "\n");
	ft_free_dict (&dict);
	return (err);
}
