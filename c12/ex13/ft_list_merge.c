/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:24:35 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/16 15:47:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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
