/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:42:41 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/07 15:21:59 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!str)
		return (0);
	start = 0;
	while (IS_SPACES(str[start]))
		start++;
	end = ft_strlen(str);
	while (start != end && (IS_SPACES(str[end]) || str[end] == 0))
		end--;
	len = (end != start || str[start]) ? ++end - start : 0;
	res = ft_strsub(str, start, len);
	return (res);
}
