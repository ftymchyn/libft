/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:15:07 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/01 11:19:26 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t k;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		k = 0;
		while (haystack[i + k] && i + k < len)
		{
			if (haystack[i + k] != needle[k])
				break ;
			if (haystack[i + k] == needle[k] && needle[k + 1] == '\0')
				return ((char*)haystack + i);
			k++;
		}
		i++;
	}
	return (0);
}
