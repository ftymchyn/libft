/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:19:40 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/01/04 17:19:41 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stack_push(t_stack **begin_stack, void *data)
{
	t_stack	*new;
	t_stack	*head;

	new = stack_create_elem(data, sizeof(*data));
	if (!new || !begin_stack)
		return ;
	if (*begin_stack)
	{
		head = *begin_stack;
		while (head)
		{
			if (head->next == NULL)
			{
				head->next = new;
				return ;
			}
			head = head->next;
		}
	}
	else
		*begin_stack = new;
}
