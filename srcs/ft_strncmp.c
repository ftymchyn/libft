/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:42:11 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/01 11:46:02 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	u1;
	unsigned char	u2;

	while (n--)
	{
		u1 = *(unsigned char*)s1;
		u2 = *(unsigned char*)s2;
		if (u1 != u2 || u1 == 0 || u2 == 0)
			return (u1 - u2);
		s1++;
		s2++;
	}
	return (0);
}
