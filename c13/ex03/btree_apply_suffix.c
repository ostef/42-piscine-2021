/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:33:41 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/21 13:42:43 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf) (void *))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_suffix (root->left, applyf);
	if (root->right)
		btree_apply_suffix (root->right, applyf);
	(*applyf)(root->item);
}
