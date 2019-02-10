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

# define MAX_LONG 9223372036854775807
# define ABS(x) (x < 0 ? -x : x)
# define IS_WHITESPACES(x) ((x >= 9 && x <= 13) || x == 32)
# define IS_SPACES(x) (x == ' ' || x == '\n' || x == '\t')
# define IS_NUMERIC(x) (x >= '0' && x <= '9')
# define BUFF_SIZE 8192

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_stack
{
	struct s_stack	*next;
	void			*data;
}					t_stack;

typedef struct		s_tmap
{
	struct s_tmap	*left;
	struct s_tmap	*right;
	void			*key;
	void			*value;
	size_t			value_s;
}					t_treemap;

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
char				*ft_llitoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_sqrt(int nb);
int					ft_pow(int x, int pow);
int					get_next_line(const int fd, char **line);
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
t_stack				*stack_create_elem(void *data, size_t size);
void				stack_push(t_stack **begin_stack, void *data, size_t size);
void				*stack_pop(t_stack **begin_stack);
void				*stack_unshift(t_stack **begin_stack);
#endif
