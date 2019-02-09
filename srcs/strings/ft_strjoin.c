/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:32:17 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/01 17:42:18 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1len;
	size_t	s2len;

	if (!s1 && !s2)
		return (0);
	s1len = s1 ? ft_strlen(s1) : 0;
	s2len = s2 ? ft_strlen(s2) : 0;
	res = ft_strnew(s1len + s2len);
	if (!res)
		return (0);
	if (s1)
		ft_strcat(res, s1);
	if (s2)
		ft_strcat(res, s2);
	return (res);
}
