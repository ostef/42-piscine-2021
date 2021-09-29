/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:25:07 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/16 15:08:27 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*end;

	if (*begin_list)
	{
		end = *begin_list;
		while (end->next)
			end = end->next;
		end->next = ft_create_elem (data);
	}
	else
	{
		*begin_list = ft_create_elem (data);
	}
}
