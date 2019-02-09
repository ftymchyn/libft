/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:00:51 by dryshchu          #+#    #+#             */
/*   Updated: 2017/10/31 20:32:37 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char	*st1;
	char	*st2;
	size_t	i;

	st1 = (char*)str1;
	st2 = (char*)str2;
	i = 0;
	while (i < n)
	{
		st1[i] = st2[i];
		i++;
	}
	return (st1);
}
