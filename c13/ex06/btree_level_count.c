/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:54:18 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/23 14:53:32 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	btree_count_helper(t_btree *root, int accumulator)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	if (accumulator == 0)
		return (1);
	left = btree_count_helper (root->left, accumulator - 1);
	right = btree_count_helper (root->right, accumulator - 1);
	return (left || right);
}

int	btree_level_count(t_btree *root)
{
	int	level;

	level = 0;
	while (btree_count_helper (root, level))
		level += 1;
	return (level);
}
