# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 16:13:50 by pzarmehr          #+#    #+#              #
#    Updated: 2017/10/20 19:47:12 by mdezitte         ###   ########.fr        #
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
	  error.c \
	  ft_atoi.c \
	  ft_isdigit.c \
	  ft_putnbr.c

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
