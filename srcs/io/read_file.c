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
static void	print_error(const char *filename, const char *e1, const char *e2)
{
	ft_putstr_fd(e1, 2);
	ft_putstr_fd(e2, 2);
	ft_putstr_fd(" \"", 2);
	ft_putstr_fd(filename, 2);
	ft_putendl_fd("\"", 2);
}
char		*read_file(const char *filename)
{
	char	*result;
	char	*tmp;
	char	buffer[BUFF_SIZE];
	int		bytes;
	int		fd;

	result = NULL;
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		while ((bytes = read(fd, buffer, BUFF_SIZE - 1)) > 0)
		{
			buffer[bytes] = '\0';
			tmp = ft_strjoin(result, buffer);
			free((void*)result);
			result = tmp;
		}
		if (bytes == -1)
			print_error(filename, "read() error : ", strerror(errno));
	}
	else
		print_error(filename, "open() error : ", strerror(errno));
	return (result);
}