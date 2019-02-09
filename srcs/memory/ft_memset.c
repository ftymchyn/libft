/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:56:59 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/10/30 15:34:33 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*st;

	st = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		st[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
