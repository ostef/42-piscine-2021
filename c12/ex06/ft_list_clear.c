/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:37:55 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/15 02:06:07 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct) (void *))
{
	t_list	*curr;
	t_list	*next;

	curr = begin_list;
	while (curr)
	{
		next = curr->next;
		if (free_fct)
			(*free_fct)(curr->data);
		free (curr);
		curr = next;
	}
}
