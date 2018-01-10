/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_unshift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:34:05 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/01/10 21:34:06 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*stack_unshift(t_stack **begin_stack)
{
	t_stack	*head;
	t_stack	*next;
	void	*res;

	if (begin_stack || *begin_stack)
	{
		head = *begin_stack;
		next = head->next;
		*begin_stack = next;
		res = head->data;
		free(head);
		return (res);
	}
	return (NULL);
}