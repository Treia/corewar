# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 11:48:22 by pzarmehr          #+#    #+#              #
#    Updated: 2017/10/20 18:33:39 by mdezitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEASM = asm
NAMECOR = corewar
CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_LIBFT = ./libft/includes
LFT = -L ./libft/ -l ft

PATH_ASM = ./sources/asm/
PATH_COR = ./sources/corewar/
PATH_SRC = ./sources/
PATH_INC = ./includes/

# ASM #

ASM_CORE = main.c
ASM_SRC_CORE = $(addprefix core/, $(ASM_CORE))

ASM_READDER = asm_read_file.c
ASM_SRC_READDER = $(addprefix asm_readder/, $(ASM_READDER))

SRCASM = $(ASM_SRC_CORE) $(ASM_SRC_READDER)

# COR #

SRCCOR = cor_main.c \
		cor_run.c \
		error.c \
		print_error.c \
		get_players.c
SRCALL =

OBJASM = $(patsubst %.c,%.o,$(addprefix $(PATH_ASM), $(SRCASM)))
OBJCOR = $(patsubst %.c,%.o,$(addprefix $(PATH_COR), $(SRCCOR)))
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
