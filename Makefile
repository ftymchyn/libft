# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 14:33:59 by ftymchyn          #+#    #+#              #
#    Updated: 2017/11/22 18:10:02 by ftymchyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = libft.a
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCL_DIR = includes/
FLAGS	 = -Wall -Wextra -Werror -I $(INCL_DIR) -c
CC		 = gcc
SRCS	 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
		   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		   ft_sqrt.c ft_pow.c btree_create_node.c btree_apply_prefix.c\
		   btree_apply_infix.c btree_apply_suffix.c btree_insert_node.c \
		   btree_get_node.c btree_get_value.c btree_delete_node.c \
		   get_next_line.c stack_create_elem.c stack_pop.c stack_push.c 
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all : $(NAME)
	@echo "$(NAME) successful build"

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(FLAGS) $< -o $@

clean :
	@rm -f $(OBJS_DIR)*.o

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) $@ done"

re: fclean all
