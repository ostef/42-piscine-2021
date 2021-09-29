/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkouki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:55:48 by fkouki            #+#    #+#             */
/*   Updated: 2021/09/20 04:06:30 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

static const t_uint	g_allowed_keys[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
	12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000,
	1000000, 1000000000};

#define ARRAY_SIZE(array) (int)(sizeof (array) / sizeof (*(array)))

static t_bool	ft_key_is_allowed(t_uint nbr)
{
	int	i;

	i = 0;
	while (i < ARRAY_SIZE (g_allowed_keys))
	{
		if (g_allowed_keys[i] == nbr)
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}

void	ft_add_to_dict(t_dict *dict, t_uint nbr, char *str)
{
	if (!ft_key_is_allowed (nbr))
	{
		free (str);
		return ;
	}
	if (dict->count == dict->capacity)
		ft_grow_dict (dict);
	dict->data[dict->count].nbr = nbr;
	dict->data[dict->count].str = str;
	dict->count += 1;
}

char	*ft_dict_get(t_dict *dict, t_uint nbr)
{
	int	i;

	i = 0;
	while (i < dict->count)
	{
		if (dict->data[i].nbr == nbr)
			return (dict->data[i].str);
		i += 1;
	}
	return (NULL);
}

void	ft_sort_dict(t_dict *dict)
{
	int				i;
	t_dict_entry	temp;

	i = 0;
	while (i < dict->count - 1)
	{
		if (dict->data[i].nbr > dict->data[i + 1].nbr)
		{
			temp = dict->data[i];
			dict->data[i] = dict->data[i + 1];
			dict->data[i + 1] = temp;
			i = 0;
		}
		else
		{
			i += 1;
		}
	}
}
