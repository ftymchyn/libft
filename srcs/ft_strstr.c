/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 21:55:27 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/01 11:21:46 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t k;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	i = 0;
	while (haystack[i])
	{
		k = 0;
		while (haystack[i + k])
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
