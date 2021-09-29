/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:56:49 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/23 14:56:01 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

static void	ft_grow_queue(t_btree ***queue, int *count)
{
	t_btree	**new_data;
	int		i;

	new_data = malloc (sizeof (t_btree *) * (count[1] * 2 + 8));
	i = 0;
	while (i < count[0])
	{
		new_data[i] = (*queue)[i];
		i += 1;
	}
	free (*queue);
	*queue = new_data;
	count[1] = count[1] * 2 + 8;
}

static int	btree_enqueue_level(t_btree *root, int accumulator,
		t_btree ***queue, int *count)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	if (accumulator == 0)
	{
		if (count[0] == count[1])
			ft_grow_queue (queue, count);
		(*queue)[count[0]] = root;
		count[0] += 1;
		return (1);
	}
	left = btree_enqueue_level (root->left, accumulator - 1, queue, count);
	right = btree_enqueue_level (root->right, accumulator - 1, queue, count);
	return (left || right);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf) (void *item, int current_level, int is_first_elem))
{
	int		level;
	t_btree	**queue;
	int		count[2];
	int		i;

	level = 0;
	queue = NULL;
	count[0] = 0;
	count[1] = 0;
	while (btree_enqueue_level (root, level, &queue, count))
	{
		i = 0;
		while (i < count[0])
		{
			(*applyf)(queue[i]->item, level, i == 0);
			i += 1;
		}
		count[0] = 0;
		level += 1;
	}
	free (queue);
}
