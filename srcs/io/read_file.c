/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:20:06 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/12/06 13:05:19 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*read_file(const char *filename)
{
	char	*result;
	char	*tmp;
	char	buffer[SBUFF_SIZE];
	int		bytes;
	int		fd;

	result = NULL;
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		while ((bytes = read(fd, buffer, SBUFF_SIZE - 1)) > 0)
		{
			buffer[bytes] = '\0';
			tmp = ft_strjoin(result, buffer);
			free((void*)result);
			result = tmp;
		}
		if (bytes == -1)
			ft_dprintf(2,
				"read() error : %s \"%s\"\n", strerror(errno), filename);
	}
	else
	ft_dprintf(2, "open() error : %s \"%s\"\n", strerror(errno), filename);
	return (result);
}