/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahextoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:03:52 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/12/04 21:03:54 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int				ft_ahextoi(const char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] && str[i] != 'x' && str[i] != 'X')
		i++;
	if (str[i])
		i++;
	while (str[i])
	{
		n = n * 16 + to_upper(str[i]) - ((str[i] < 65) ? 48 : 55);
		i++;
	}
	return (n);
}
