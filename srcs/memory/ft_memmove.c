/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:19:01 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/10/31 19:30:57 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = 0;
	if (!dst || !src)
		return (dst);
	while (i < len)
	{
		if (src < dst)
			dst1[len - i - 1] = src1[len - i - 1];
		else if (src > dst)
			dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
