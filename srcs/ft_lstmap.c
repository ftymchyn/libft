/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:13:54 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/06 11:27:04 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *node;

	head = 0;
	if (lst && f)
	{
		head = (*f)(lst);
		if (!head)
			return (0);
		lst = lst->next;
		node = head;
		while (lst)
		{
			node->next = (*f)(lst);
			if (!node->next)
				return (head);
			lst = lst->next;
			node = node->next;
		}
	}
	return (head);
}
