/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:30:21 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/21 13:33:07 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf) (void *, void *))
{
	void	*result;

	if (!root)
		return (NULL);
	result = btree_search_item (root->left, data_ref, cmpf);
	if (result)
		return (result);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	result = btree_search_item (root->right, data_ref, cmpf);
	if (result)
		return (result);
	return (NULL);
}
