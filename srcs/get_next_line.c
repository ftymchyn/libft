/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:20:06 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/28 15:22:59 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cmpf(void *n1, void *n2)
{
	int	num1;
	int	num2;

	num1 = *(int*)n1;
	num2 = *(int*)n2;
	if (num1 < num2)
		return (-1);
	else if (num1 > num2)
		return (1);
	return (0);
}

static size_t	getlinelen(char *str)
{
	char	*s;

	s = ft_strchr(str, '\n');
	if (!s)
		return (ft_strlen(str));
	return (s - str);
}

static int		search_saved_line(t_treemap **root, int fd, char **res)
{
	t_treemap	*node;
	char		*s_buff;
	size_t		len;
	size_t		s_buff_len;

	node = btree_get_node(*root, &fd, cmpf);
	*res = NULL;
	if (!node)
		return (0);
	s_buff = (char*)node->value;
	s_buff_len = ft_strlen(s_buff);
	len = getlinelen(s_buff);
	*res = ft_strsub(s_buff, 0, len);
	if (!*res)
		return (-1);
	node->value = ft_strjoin("", s_buff[len] ? s_buff + len + 1 : s_buff + len);
	if (!node->value || !((char*)node->value)[0])
		free(btree_delete_node(root, &fd, cmpf));
	free(s_buff);
	return (ft_strlen(*res) == s_buff_len ? 0 : 1);
}

static char		*get_line(t_treemap **root, int fd, char **res, char *buff)
{
	t_treemap	*node;
	char		*result;
	char		*tmp;
	size_t		tmp_len;
	size_t		buff_len;

	tmp = ft_strsub(buff, 0, getlinelen(buff));
	result = ft_strjoin(*res, tmp);
	if (!tmp || !result)
		return (*res);
	free(*res);
	tmp_len = ft_strlen(tmp);
	buff_len = ft_strlen(buff);
	if (tmp_len == buff_len)
		*res = result;
	else if (tmp_len != buff_len - 1)
	{
		node = btree_create_node(&fd, sizeof(int), NULL, 0);
		node->value = (void*)ft_strjoin("", buff + getlinelen(buff) + 1);
		btree_insert_node(root, node, cmpf);
	}
	free(tmp_len != buff_len ? buff : NULL);
	free(tmp);
	return (tmp_len == buff_len ? NULL : result);
}

int				get_next_line(const int fd, char **line)
{
	static t_treemap	*root = NULL;
	char				*buff;
	char				*res;
	int					ret;

	if (!line || (ret = search_saved_line(&root, (int)fd, &res)))
	{
		if (!line || ret == -1)
			return (-1);
		*line = res;
		return (1);
	}
	buff = ft_strnew(BUFF_SIZE);
	while (buff && (ret = read(fd, buff, BUFF_SIZE)) != -1 && (ret || res))
	{
		buff[ret] = '\0';
		*line = get_line(&root, fd, &res, buff);
		if (!ret && res)
			*line = res;
		if (*line)
			return (1);
	}
	free(buff);
	return (buff ? ret : -1);
}
