/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:36:44 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/12 12:44:48 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_word_len(const char *str, size_t i, char c)
{
	size_t k;

	k = 0;
	while (str[i] != c && str[i] != 0)
	{
		k++;
		i++;
	}
	return (k);
}

static int		ft_get_start_next_word(const char *str, size_t i, char c)
{
	while (str[i])
	{
		if (str[i] != c)
			return (i);
		i++;
	}
	return (i);
}

static int		ft_count_words(const char *str, char c)
{
	size_t		i;
	size_t		words;

	if (!str)
		return (0);
	i = ft_get_start_next_word(str, 0, c);
	words = 0;
	while (str[i] != 0)
	{
		if (str[i] == c || str[i + 1] == 0)
		{
			words++;
			if (str[i + 1] == 0)
				return (words);
			i = ft_get_start_next_word(str, i, c);
		}
		else
			i++;
	}
	return (words);
}

int				free_arr(char **words, int w_cut)
{
	int i;

	if (*words)
	{
		i = 0;
		while (i < w_cut)
		{
			free(words[i]);
			i++;
		}
		free(words);
	}
	return (1);
}

char			**ft_strsplit(const char *str, char c)
{
	char		**words;
	size_t		i;
	size_t		w_len;
	int			w_count;
	int			w_cut;

	if (!str)
		return (0);
	w_count = ft_count_words(str, c);
	words = (char**)malloc(sizeof(words) * (w_count + 1));
	if (!words)
		return (0);
	i = 0;
	w_cut = -1;
	while (++w_cut < w_count)
	{
		i = ft_get_start_next_word(str, i, c);
		w_len = ft_get_word_len(str, i, c);
		words[w_cut] = ft_strsub(str, i, w_len);
		if (!words[w_cut] && free_arr(words, w_cut))
			return (0);
		i += w_len;
	}
	words[w_cut] = 0;
	return (words);
}
