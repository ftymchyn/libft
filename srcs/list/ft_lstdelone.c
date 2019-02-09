/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:01:51 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/02 20:09:19 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *node;

	if (alst && del)
	{
		node = *alst;
		if (node)
		{
			(*del)(node->content, node->content_size);
			free(node);
		}
		*alst = 0;
	}
}
