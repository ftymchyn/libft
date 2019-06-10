/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:16 by ftymchyn          #+#    #+#             */
/*   Updated: 2017/11/20 14:09:35 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdarg.h>

# define MAX_LONG 9223372036854775807
# define ABS(x) (x < 0 ? -x : x)
# define MAX(x, y) (x < y ? y : x)
# define MIN(x, y) (x < y ? x : y)
# define IS_WHITESPACES(x) ((x >= 9 && x <= 13) || x == 32)
# define IS_SPACES(x) (x == ' ' || x == '\n' || x == '\t')
# define IS_NUMERIC(x) (x >= '0' && x <= '9')
# define BUFF_SIZE 8192

typedef struct		s_tmap
{
	struct s_tmap	*left;
	struct s_tmap	*right;
	void			*key;
	void			*value;
	size_t			value_s;
}					t_treemap;

typedef struct		s_darr
{
	unsigned char	*data;
	size_t			data_type_size;
	size_t			size;
	size_t			capacity;
}					t_darr;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
double				ft_atof(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
t_darr				ft_strsplit_vec(const char *str, char c);
char				*ft_llitoa(long long n);
char				*ft_ullitoa_radix(unsigned long long n, int radix);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);

int					ft_sqrt(int nb);
int					ft_pow(int x, int pow);
t_treemap			*btree_create_node
					(void *key, size_t key_s, void *value, size_t value_s);
void				btree_apply_prefix(t_treemap *root, void (*applyf)(void *));
void				btree_apply_infix(t_treemap *root, void (*applyf)(void *));
void				btree_apply_suffix(t_treemap *root, void (*applyf)(void *));
void				btree_insert_node
					(t_treemap **r, t_treemap *n, int (*cmpf)(void*, void*));
t_treemap			*btree_get_node
					(t_treemap *root, void *key, int (*cmpf)(void *, void *));
void				*btree_get_value
					(t_treemap *root, void *key, int (*cmpf)(void *, void *));
void				*btree_delete_node
					(t_treemap **root, void *key, int (*cmpf)(void *, void *));

void				darr_init(t_darr *darr, size_t data_type_size);
void				darr_resize(t_darr *darr, size_t new_size);
void				darr_insert(t_darr *darr, size_t index, void *data);
void				darr_erase(t_darr *darr, size_t index, void *return_data);
void				*darr_at(t_darr *darr, size_t index);
void				*darr_last(t_darr *darr);
void				*darr_create_last(t_darr *darr);
void				darr_pushback(t_darr *darr, void *data);
void				darr_foreach(t_darr *darr, void (*applyf)(void*));
void				darr_clear(t_darr *darr, void (*destructf)(void*));

int					get_next_line(const int fd, char **line);
char				*read_file(const char *filename);
#endif
