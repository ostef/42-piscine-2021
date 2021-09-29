/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:07:13 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/18 00:34:02 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_swap_moi_ca(t_list *prev, t_list *curr)
{
	void	*temp;

	temp = prev->data;
	prev->data = curr->data;
	curr->data = temp;
}

static void	ft_sort_moi_ca(t_list **begin_list, int (*cmp) ())
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	curr = *begin_list;
	while (curr && curr->next)
	{
		if ((*cmp)(curr->data, curr->next->data) > 0)
		{
			ft_swap_moi_ca(curr, curr->next);
			prev = NULL;
			curr = *begin_list;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

static void	ft_merge_moi_ca(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*curr;

	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
	}
	else
	{
		curr = *begin_list1;
		while (curr->next)
			curr = curr->next;
		curr->next = begin_list2;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp) ())
{
	ft_merge_moi_ca (begin_list1, begin_list2);
	ft_sort_moi_ca (begin_list1, cmp);
}
