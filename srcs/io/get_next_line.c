/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:20:06 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/12/06 13:05:19 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		substr_line(t_fbuff *b, char **line)
{
	int		result;
	size_t	flen;
	char	*fptr;
	char	*tmpstr;
	char	*substr;

	if ((result = b->idx != b->len))
	{
		result = (NULL != (fptr = ft_strchr(b->str + b->idx, '\n')));
		flen = result ?
			(fptr - (b->str + b->idx)) : (b->str + b->len) - (b->str + b->idx);
		tmpstr = *line;
		substr = ft_strsub(b->str, b->idx, flen);
		if (substr[flen - 1] == '\r')
			substr[flen - 1] = '\0';
		*line = ft_strjoin(tmpstr, substr);
		ft_strdel(&tmpstr);
		ft_strdel(&substr);
		b->idx += (result ? flen + 1 : flen );
		if (!result || b->idx == b->len)
		{
			b->idx = 0;
			b->len = 0;
		}
	}
	return (result);
}

static t_fbuff	*get_fd_buffer(const int fd, t_darr **buffers)
{
	t_fbuff	*result;
	int		i;

	if (*buffers == NULL && (*buffers = ft_memalloc(sizeof(t_darr))))
		darr_init(*buffers, sizeof(t_fbuff));
	result = NULL;
	i = 0;
	while (*buffers && !result && i < (*buffers)->size)
	{
		result = (t_fbuff*)darr_at(*buffers, i);
		if (result->fd != fd)
			result = NULL;
		i++;
	}
	if (*buffers && !result && (result = darr_create_last(*buffers)))
	{
		result->fd = fd;
		result->str = (char*)ft_strnew(DBUFF_SIZE);
	}
	return (result);
}

static void		clear_fd_buffer(const int fd, t_darr **buffers)
{
	t_fbuff	*buff;
	int		i;

	buff = NULL;
	i = 0;
	while (*buffers && i < (*buffers)->size)
	{
		buff = (t_fbuff*)darr_at(*buffers, i);
		if (buff->fd == fd)
		{
			ft_strdel(&buff->str);
			darr_erase(*buffers, i, NULL);
			break;
		}
		i++;
	}
	if (*buffers && (*buffers)->size == 0)
	{
		darr_clear(*buffers, NULL);
		ft_memdel((void**)buffers);
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_darr	*buffers = NULL;
	t_fbuff			*buff;
	char			*tmp;
	int				result;

	buff = get_fd_buffer(fd, &buffers);
	tmp = NULL;
	result = -1;
	while (buff && buff->str && line && result < 0)
	{
		if (0 == (result = substr_line(buff, &tmp)))
		{
			result = -1;
			if (1 > (buff->len = read(fd, buff->str, DBUFF_SIZE)) && tmp)
				result = 1;
			else if (buff->len == 0)
				result = 0;
			else if (buff->len == -1)
				break ;
		}
		if (result != -1)
			*line = tmp;
	}
	if (result != 1)
		clear_fd_buffer(fd, &buffers);
	return (result);
}
