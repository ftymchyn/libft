/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:27:17 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/01/04 17:27:19 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*stack_pop(t_stack **begin_stack)
{
	t_stack	*head;
	t_stack	*prev;
	void	*res;

	if (begin_stack || *begin_stack)
	{
		head = *begin_stack;
		if (!head->next)
		{
			*begin_stack = NULL;
			res = head->data;
			free(head);
			return (res);
		}
		while (head)
		{
			prev = head;
			head = prev->next;
			if (!head->next)
			{
				prev->next = NULL;
				res = head->data;
				free(head);
				return (res);
			}
		}
	}
	return (NULL);
}
