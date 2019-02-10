/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:56:36 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/02 12:34:42 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits_len(long long n)
{
	int len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_llitoa(long long n)
{
	unsigned long long	tmp;
	char				*res;
	int					sign;
	int					len;

	sign = n < 0 ? 1 : 0;
	len = get_digits_len(n);
	tmp = ABS(n);
	res = ft_strnew(len + sign);
	if (!res)
		return (0);
	if (!n)
		res[0] = '0';
	while (tmp)
	{
		res[sign ? len : len - 1] = tmp % 10 + '0';
		tmp /= 10;
		len--;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
