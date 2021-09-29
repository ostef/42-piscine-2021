/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:52:58 by mrubis            #+#    #+#             */
/*   Updated: 2021/09/20 04:04:36 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

t_dict	ft_make_dict(int n)
{
	t_dict	result;

	result.data = malloc(sizeof (t_dict_entry) * n);
	result.count = 0;
	result.capacity = n;
	return (result);
}

void	ft_free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict->count)
	{
		free (dict->data[i].str);
		i += 1;
	}
	free(dict->data);
	dict->data = NULL;
	dict->count = 0;
	dict->capacity = 0;
}

void	ft_grow_dict(t_dict *dict)
{
	t_dict_entry	*new_data;
	int				i;

	new_data = malloc (sizeof (t_dict_entry) * dict->capacity * 2);
	i = 0;
	while (i < dict->count)
	{
		new_data[i] = dict->data[i];
		i += 1;
	}
	free(dict->data);
	dict->data = new_data;
	dict->capacity *= 2;
}
