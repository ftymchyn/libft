/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:28:40 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/01 11:40:54 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char u1;
	unsigned char u2;

	while (1)
	{
		u1 = *(unsigned char*)s1;
		u2 = *(unsigned char*)s2;
		if (u1 != u2 || u1 == 0 || u2 == 0)
			return (u1 - u2);
		s1++;
		s2++;
	}
}
