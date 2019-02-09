# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 14:33:59 by ftymchyn          #+#    #+#              #
#    Updated: 2019/02/09 18:10:02 by ftymchyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = gcc
MAKE_LIB    = ar rc

CFLAGS      = -Wall -Wextra -Werror

INCL_DIR    = ./includes
SRCS_DIR    = ./srcs
OBJS_DIR    = ./obj

HEADERS     = libft.h
HEADERS    := $(addprefix $(INCL_DIR)/, $(HEADERS))

SRCS        = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c
SRCS       += ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c
SRCS       += ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c
SRCS       += ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c
SRCS       += ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c
SRCS       += ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c
SRCS       += ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c
SRCS       += ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c
SRCS       += ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c
SRCS       += ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c
SRCS       += ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c
SRCS       += ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
SRCS       += ft_sqrt.c ft_pow.c btree_create_node.c btree_apply_prefix.c
SRCS       += btree_apply_infix.c btree_apply_suffix.c btree_insert_node.c
SRCS       += btree_get_node.c btree_get_value.c btree_delete_node.c
SRCS       += get_next_line.c stack_create_elem.c stack_pop.c stack_push.c
SRCS       += stack_unshift.c

OBJS        = $(SRCS:.c=.o)

VPATH       = $(SRCS_DIR)


.PHONY: all clean fclean re


all         : $(NAME)

$(NAME)     : $(OBJS_DIR) $(OBJS) $(HEADERS)
	@$(MAKE_LIB) $(NAME) $(addprefix $(OBJS_DIR)/, $(OBJS))
	@printf "\e[38;5;46m./$(NAME)   SUCCESSFUL BUILD 🖥\e[0m\n"

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS)     : %.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ -I $(INCL_DIR)/

clean       :
	rm -rf $(OBJS_DIR)

fclean      : clean
	rm -f $(NAME)

re          : fclean all
