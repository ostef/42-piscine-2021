/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:58:49 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/17 14:38:29 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_swap_members(t_list *a, t_list *b)
{
	t_list	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;
	t_list	*second;

	if (!begin_list)
		return ;
	prev = NULL;
	curr = begin_list;
	second = begin_list->next;
	if (!second)
		return ;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	ft_swap_members (begin_list, prev);
	second->next = prev;
}
