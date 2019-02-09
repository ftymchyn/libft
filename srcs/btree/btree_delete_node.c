/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delete_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:36:45 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/21 21:36:46 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_treemap	*search_and_replace(t_treemap *parent)
{
	t_treemap	*tmp;
	t_treemap	*left;
	t_treemap	*right;

	left = parent->left;
	right = parent->right;
	parent = parent->left;
	while (parent)
	{
		tmp = parent->right;
		if (!tmp->left && !tmp->right)
			parent->right = NULL;
		else if (!tmp->right)
		{
			parent->right = tmp->left;
			break ;
		}
		parent = parent->right;
	}
	tmp->left = left;
	tmp->right = right;
	return (tmp);
}

static t_treemap	*erase_node(t_treemap **node)
{
	t_treemap *tmp;

	tmp = *node;
	if (!tmp->left && !tmp->right)
		*node = NULL;
	else if (tmp->left && !tmp->right)
		*node = tmp->left;
	else if (tmp->right && !tmp->left)
		*node = tmp->right;
	else if (tmp->left && !tmp->left->right)
	{
		*node = tmp->left;
		(*node)->right = tmp->right;
	}
	else if (tmp->right && !tmp->right->left)
	{
		*node = tmp->right;
		(*node)->left = tmp->left;
	}
	else
		*node = search_and_replace(tmp);
	tmp->left = NULL;
	tmp->right = NULL;
	return (tmp);
}

void				*btree_delete_node
	(t_treemap **root, void *key, int (*cmpf)(void *, void *))
{
	t_treemap	**node;
	t_treemap	*res;
	void		*value;
	int			cmp;

	if ((!root && !*root) || !cmpf)
		return (0);
	node = root;
	while (*node)
	{
		if ((cmp = (*cmpf)(key, (*node)->key)) == 0)
		{
			res = erase_node(node);
			value = res->value;
			free(res->key);
			free(res);
			return (value);
		}
		if (cmp > 0)
			node = &(*node)->right;
		else
			node = &(*node)->left;
	}
	return (0);
}
