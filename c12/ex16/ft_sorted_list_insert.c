/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:54:16 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/16 16:16:41 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_insert(t_list **begin_list, t_list *prev, t_list *curr,
		void *data)
{
	if (!prev)
	{
		*begin_list = ft_create_elem (data);
		(*begin_list)->next = curr;
	}
	else
	{
		prev->next = ft_create_elem (data);
		prev->next->next = curr;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp) ())
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		if ((*cmp)(curr->data, data) > 0)
			break ;
		prev = curr;
		curr = curr->next;
	}
	ft_insert (begin_list, prev, curr, data);
}
