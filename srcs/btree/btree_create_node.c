/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 12:14:14 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/07 10:41:24 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_treemap	*btree_create_node
	(void *key, size_t key_s, void *value, size_t value_s)
{
	t_treemap	*new;

	new = (t_treemap*)malloc(sizeof(t_treemap));
	if (!new || !key)
		return (0);
	new->left = 0;
	new->right = 0;
	new->key = ft_memalloc(key_s);
	if (!key)
		return (0);
	ft_memcpy(new->key, key, key_s);
	new->value = value ? ft_memalloc(value_s) : 0;
	new->value_s = new->value ? value_s : 0;
	if (new->value)
		ft_memcpy(new->value, value, value_s);
	return (new);
}
