/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:34:57 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/06 19:39:13 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char u[2];
	unsigned char uc;

	uc = (unsigned char)c;
	if (uc < 128)
	{
		write(1, &uc, 1);
	}
	else
	{
		u[0] = uc <= 0xbf ? 0xc2 : 0xc3;
		u[1] = uc <= 0xbf ? uc : uc - 64;
		write(1, u, 2);
	}
}
