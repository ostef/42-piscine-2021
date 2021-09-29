/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:46:41 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/20 15:29:01 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf) (void *, void *))
{
	t_btree	*curr;

	if (!(*root))
	{
		*root = btree_create_node (item);
		return ;
	}
	curr = *root;
	if ((*cmpf)(item, curr->item) >= 0)
		btree_insert_data (&curr->right, item, cmpf);
	else
		btree_insert_data (&curr->left, item, cmpf);
}
