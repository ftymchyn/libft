/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:36:44 by ftymchyn          #+#    #+#             */
/*   Updated: 2019/04/13 12:44:48 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_darr	ft_strsplit_vec(const char *str, char c)
{
	t_darr	result;
	char	**split;
	int		i;

	darr_init(&result, sizeof(char**));
	split = ft_strsplit(str,c);
	i = 0;
	if (split)
	{
		while (split[i])
		{
			darr_pushback(&result, (void*)(split + i));
			i++;
		}
		free(split);
	}
	return (result);
}