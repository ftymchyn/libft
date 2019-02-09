/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:45:42 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/12 13:10:56 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = 0;
	new->content = content ? ft_memalloc(content_size) : 0;
	new->content_size = new->content ? content_size : 0;
	if (new->content)
		ft_memcpy(new->content, content, content_size);
	return (new);
}
