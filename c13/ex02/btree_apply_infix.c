/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:31:04 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/21 13:42:25 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf) (void *))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_infix (root->left, applyf);
	(*applyf)(root->item);
	if (root->right)
		btree_apply_infix (root->right, applyf);
}
