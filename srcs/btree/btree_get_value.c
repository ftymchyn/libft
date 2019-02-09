/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_get_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:29:24 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/21 21:29:25 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_get_value
	(t_treemap *root, void *key, int (*cmpf)(void *, void *))
{
	t_treemap *node;

	node = btree_get_node(root, key, cmpf);
	return (node ? node->value : 0);
}
