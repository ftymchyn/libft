/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_get_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:13:31 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/21 21:13:33 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_treemap	*btree_get_node
	(t_treemap *root, void *key, int (*cmpf)(void *, void *))
{
	int	cmp;

	if (root && key && cmpf)
	{
		cmp = (*cmpf)(key, root->key);
		if (cmp == 0)
			return (root);
		if (cmp > 0)
			return (btree_get_node(root->right, key, cmpf));
		else
			return (btree_get_node(root->left, key, cmpf));
	}
	return (0);
}
