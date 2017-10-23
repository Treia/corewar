# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 16:13:50 by pzarmehr          #+#    #+#              #
#    Updated: 2017/10/21 18:47:24 by mdezitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_SRC = ./
PATH_INC = ./includes/

SRC = ft_strlen.c \
	  ft_put1.c \
	  ft_put2.c \
	  ft_error.c \
	  ft_str.c \
	  get_next_line.c \
	  ft_bzero.c \
	  ft_memalloc.c \
	  ft_strequ.c \
	  ft_strtrim.c \
	  ft_memdel.c \
	  ft_strcat.c \
	  print_error.c \
	  syntax_error.c \
	  system_error.c \
	  ft_read_file.c \
	  ft_memjoin.c \
	  ft_putmemory.c \
	  ft_memcpy.c \
	  error.c \
	  ft_atoi.c \
	  ft_isdigit.c \
	  ft_putnbr.c \
	  ft_isnum.c \
	  ft_strsplit.c \
	  ft_strncpy.c \
	  ft_tablen.c \
	  ft_memtabdel.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^ -I $(PATH_INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
