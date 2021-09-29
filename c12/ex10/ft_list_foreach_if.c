/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:44:43 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/16 15:37:14 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f) (void *),
		void *data_ref, int (*cmp) ())
{
	t_list	*curr;

	curr = begin_list;
	while (curr)
	{
		if ((*cmp)(curr->data, data_ref) == 0)
			(*f)(curr->data);
		curr = curr->next;
	}
}
