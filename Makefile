# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 11:48:22 by pzarmehr          #+#    #+#              #
#    Updated: 2017/10/24 18:24:59 by mdezitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEASM = asm
NAMECOR = corewar
CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_LIBFT = ./libft/includes
LFT = -L ./libft/ -l ft -lncurses

PATH_ASM = ./sources/asm/
PATH_COR = ./sources/corewar/
PATH_SRC = ./sources/
PATH_INC = ./includes/

# INCLUDES #

INC_FILES = asm.h \
			op.h \
			corewar.h

INCLUDES = $(addprefix $(PATH_INC), $(INC_FILES))
# ASM #

ASM_CORE = main.c \
			asm_usage.c \
			asm_syntax_error.c
ASM_SRC_CORE = $(addprefix core/, $(ASM_CORE))

ASM_READDER = asm_get_file_content.c \
				asm_skip_commented_line.c \
				asm_get_next_instruct.c \
				asm_get_asm_from_file_content.c \
				asm_get_labels_and_instructs.c
ASM_SRC_READDER = $(addprefix asm_readder/, $(ASM_READDER))

ASM_STRUCT = asm_t_header_init_from_file.c \
				asm_t_header_get_datas.c \
				asm_t_label.c \
				asm_t_label_init_from_file.c \
				asm_t_instruct.c \
				asm_t_instruct_init_from_file.c \
				asm_t_instruct_init_list_from_file.c \
				asm_t_instruct_param.c \
				asm_t_word_type_is.c \
				asm_t_word_type_to_string.c \
				asm_get_word_type.c
ASM_SRC_STRUCT = $(addprefix asm_struct/, $(ASM_STRUCT))

ASM_TOOLS = asm_error_tools.c \
				asm_is_label_char.c
ASM_SRC_TOOLS = $(addprefix tools/, $(ASM_TOOLS))

SRCASM = $(ASM_SRC_CORE) $(ASM_SRC_READDER) $(ASM_SRC_STRUCT) $(ASM_SRC_TOOLS)

# COR #

SRCCOR = cor_main.c \
		get_players.c \
		struct_player.c \
		usage.c \
		struct_argv.c \
		resolve_dump.c \
		resolve_n.c \
		resolve_champ.c \
		resolve_verb.c \
		debug.c \
		struct_pcs.c \
		struct_game.c \
		check_cycle.c \
		print_verb.c \
		cor_run.c \
		cor_run_pc.c \
		get_wait.c \
		get_cmd.c \
		cmd_tools.c \
		cmd_live.c \
		cmd_zjmp.c \
		cmd_fork.c \
		make_player_list.c \
		print_winner.c \
		print_arena.c \
		get_pcs.c \
		error_get_players.c \
		resolve_graph.c \
		graph_init.c \
		graph_head.c \
		struct_display.c \
		graph_arena.c
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
