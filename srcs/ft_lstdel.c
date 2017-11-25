/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:27:53 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/02 20:09:45 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *node;

	if (alst && del)
	{
		node = *alst;
		if (node)
		{
			ft_lstdel(&node->next, del);
			(*del)(node->content, node->content_size);
			free(node);
		}
		*alst = 0;
	}
}
