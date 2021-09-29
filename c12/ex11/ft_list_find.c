/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:05:24 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/16 15:37:56 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp) ())
{
	t_list	*curr;

	curr = begin_list;
	while (curr)
	{
		if ((*cmp)(curr->data, data_ref) == 0)
			break ;
		curr = curr->next;
	}
	return (curr);
}
