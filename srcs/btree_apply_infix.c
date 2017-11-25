/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 21:06:32 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/07 11:57:52 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix(t_treemap *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		btree_apply_infix(root->left, applyf);
		(*applyf)(root->value);
		btree_apply_infix(root->right, applyf);
	}
}
