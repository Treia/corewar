# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 11:48:22 by pzarmehr          #+#    #+#              #
#    Updated: 2017/09/26 11:36:35 by mplanell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEASM = asm
NAMECOR = corewar
CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_LIBFT = ./libft/includes
LFT = -L ./libft/ -l ft

PATH_SRC = ./src/
PATH_INC = ./includes/

SRCASM = asm_main.c
SRCCOR = cor_main.c
SRCALL = 

OBJASM = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRCASM)))
OBJCOR = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRCCOR)))
OBJALL = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRCALL)))


all: lib $(OBJASM) $(OBJCOR) $(OBJALL)
	$(CC) $(FLAGS) -o $(NAMEASM) $(OBJASM) $(OBJALL) $(LFT)
	$(CC) $(FLAGS) -o $(NAMECOR) $(OBJCOR) $(OBJALL) $(LFT)

lib:
	make -C libft

$(NAMEASM): lib $(OBJASM) $(OBJALL)
	$(CC) $(FLAGS) -o $(NAMEASM) $(OBJASM) $(OBJALL) $(LFT)

$(NAMECOR): lib $(OBJCOR) $(OBJALL)
	$(CC) $(FLAGS) -o $(NAMECOR) $(OBJCOR) $(OBJALL) $(LFT)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^ -I $(PATH_INC) -I $(PATH_LIBFT)

clean:
	make -C libft clean
	rm -f $(OBJASM) $(OBJCOR) $(OBJALL)

fclean:
	make -C libft fclean
	rm -f $(OBJASM) $(OBJCOR) $(OBJALL)
	rm -f $(NAMEASM) $(NAMECOR)

re: fclean all

.PHONY: all clean fclean re
