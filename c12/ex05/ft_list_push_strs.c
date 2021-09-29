/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:29:56 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/17 14:18:59 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_push(t_list **begin_list, void *data)
{
	t_list	*item;

	item = ft_create_elem (data);
	item->next = *begin_list;
	*begin_list = item;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*result;
	int		i;

	result = 0;
	i = 0;
	while (i < size)
	{
		ft_push (&result, strs[i]);
		i += 1;
	}
	return (result);
}
