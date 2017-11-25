/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:42:33 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/07 11:56:33 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_node
	(t_treemap **root, t_treemap *new, int (*cmpf)(void *, void *))
{
	t_treemap *node;

	if (root && cmpf && new)
	{
		if (*root)
		{
			node = *root;
			if ((*cmpf)(new->key, node->key) >= 0)
				btree_insert_node(&node->right, new, cmpf);
			else
				btree_insert_node(&node->left, new, cmpf);
		}
		else
		{
			*root = new;
		}
	}
}
