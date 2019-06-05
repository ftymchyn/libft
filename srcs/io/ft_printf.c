/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:32:21 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/02 16:35:03 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	return (vdprintf(fd, format, ap));
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (result);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (result);
}