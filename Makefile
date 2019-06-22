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

#memory
SRCS        = ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_bzero.c
SRCS       += ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c
#strings
SRCS       += ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c
SRCS       += ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c
SRCS       += ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c
SRCS       += ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c
SRCS       += ft_strlen.c ft_strdup.c ft_strcpy.c ft_strjoin.c ft_strtrim.c
SRCS       += ft_strsplit.c ft_strsplit_vec.c
#ctype
SRCS       += ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
SRCS       += ft_toupper.c ft_tolower.c
#btree
SRCS       += btree_apply_infix.c btree_apply_suffix.c btree_insert_node.c
SRCS       += btree_get_node.c btree_get_value.c btree_delete_node.c
SRCS       += btree_create_node.c btree_apply_prefix.c
#dynarr
SRCS       += darr_init.c darr_resize.c darr_clear.c darr_at.c
SRCS       += darr_foreach.c darr_insert.c darr_pushback.c darr_erase.c
SRCS       += darr_last.c darr_create_last.c
#io
SRCS       += ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c
SRCS       += ft_putchar.c ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c
SRCS       += get_next_line.c read_file.c ft_printf.c
#math
SRCS       += ft_sqrt.c ft_pow.c
#conversions
SRCS       += ft_atoi.c ft_atof.c ft_ahextoi.c ft_llitoa.c ft_ullitoa_radix.c

OBJS        = $(SRCS:.c=.o)

SRCS_SUBDIR = memory strings ctype btree dynarr io math conversions
VPATH       = $(SRCS_DIR) $(addprefix $(SRCS_DIR)/, $(SRCS_SUBDIR)) $(OBJS_DIR)


.PHONY: all build clean fclean re


all         :
	$(MAKE) -j8 build

build       : $(NAME)

$(NAME)     : $(OBJS_DIR) $(OBJS) $(HEADERS)
	@$(MAKE_LIB) $(NAME) $(addprefix $(OBJS_DIR)/, $(OBJS))
	@printf "\n\e[38;5;46m%-40s SUCCESSFUL BUILD 🖥\e[0m\n" ./$(NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ -I $(INCL_DIR)/
	@printf "%-40s \e[38;5;49mcompiled\e[0m\n" $<

clean       :
	rm -rf $(OBJS_DIR)

fclean      : clean
	rm -f $(NAME)

re          : fclean all
