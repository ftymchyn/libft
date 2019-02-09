/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:32:21 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/02 16:35:03 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char u[2];
	unsigned char uc;

	uc = (unsigned char)c;
	if (uc < 128)
	{
		write(fd, &uc, 1);
	}
	else
	{
		u[0] = uc <= 0xbf ? 0xc2 : 0xc3;
		u[1] = uc <= 0xbf ? uc : uc - 64;
		write(fd, u, 2);
	}
}
