/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:45:26 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/16 16:07:46 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_swap_elem(t_list *prev, t_list *curr)
{
	void	*temp;

	temp = prev->data;
	prev->data = curr->data;
	curr->data = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp) ())
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	curr = *begin_list;
	while (curr && curr->next)
	{
		if ((*cmp)(curr->data, curr->next->data) > 0)
		{
			ft_swap_elem(curr, curr->next);
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
