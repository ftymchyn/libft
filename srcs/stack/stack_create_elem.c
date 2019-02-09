/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:50:47 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/01/04 15:50:48 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*stack_create_elem(void *data, size_t size)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new || !data)
		return (NULL);
	new->next = NULL;
	new->data = ft_memalloc(size);
	if (!new->data)
		return (NULL);
	ft_memcpy(new->data, data, size);
	return (new);
}
