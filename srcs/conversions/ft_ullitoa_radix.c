/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:56:36 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/02 12:34:42 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	get_digit(int num)
{
	static char* digits = "0123456789abcdef";

	return (digits[num]);
}

static int	get_digits_len(unsigned long long n, int radix)
{
	int len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= radix;
	}
	return (len);
}

char		*ft_ullitoa_radix(unsigned long long n, int radix)
{
	char	*res;
	int		len;

	if (radix < 2)
		radix = 2;
	if (radix > 16)
		radix = 16;
	len = get_digits_len(n, radix);
	res = ft_strnew(len);
	if (!res)
		return (0);
	res[0] = '0';
	while (n)
	{
		res[len - 1] = get_digit(n % radix);
		n /= radix;
		len--;
	}
	return (res);
}
