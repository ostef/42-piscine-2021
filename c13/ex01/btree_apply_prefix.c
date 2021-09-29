/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:24:30 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/21 13:44:03 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf) (void *))
{
	if (!root)
		return ;
	(*applyf)(root->item);
	if (root->left)
		btree_apply_prefix (root->left, applyf);
	if (root->right)
		btree_apply_prefix (root->right, applyf);
}
