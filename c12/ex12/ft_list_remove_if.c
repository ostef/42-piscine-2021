/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:08:49 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/16 15:45:26 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp) (), void (*free_fct) (void *))
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*begin_list = curr->next;
			if (free_fct)
				(*free_fct)(curr->data);
			free (curr);
		}
		else
		{
			prev = curr;
		}
		curr = next;
	}
}
