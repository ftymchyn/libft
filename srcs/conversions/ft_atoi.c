/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:46:08 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/08 10:24:26 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign_and_trunc(const char **str)
{
	int sign;

	while (IS_WHITESPACES(**str))
		*str += 1;
	sign = **str == '-' ? 1 : 0;
	if (**str == '+' || **str == '-')
		*str += 1;
	while (**str == '0')
		*str += 1;
	return (sign);
}

int			ft_atoi(const char *str)
{
	size_t				i;
	unsigned long		res;
	unsigned int		digit;
	int					sign;

	i = 0;
	res = 0;
	sign = get_sign_and_trunc(&str);
	while (IS_NUMERIC(str[i]))
	{
		digit = str[i] - '0';
		res = res * 10 + digit;
		i++;
	}
	if (i > 19 || res > MAX_LONG)
		return (sign ? 0 : -1);
	if (sign)
		return (-res);
	return (res);
}
