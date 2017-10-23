/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 13:51:23 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 17:03:31 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define HEADER_SIZE sizeof(t_header)
# define LEN_HEXA 16
# define BASE_HEXA "0123456789abcdef"
# define NB_OCTET_DISPLAY 64

typedef	struct			s_player
{
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	int					live;
	int					nb_live;
	struct s_player		*next;
}						t_player;

typedef	struct			s_pc
{
	int					addr;
	int					reg[REG_NUMBER];
	int					carry;
	int					last_live;
	int					wait;
	int					(*cmd)(void *, void *);
	struct s_pc			*next;
}						t_pc;

typedef	struct			s_game
{
	t_player			*players;
	t_pc				*pcs;
	char				arena[MEM_SIZE];
	int					dump;
	int					verb;
	int					winner;
}						t_game;

typedef	struct			s_cycle
{
	int					current;
	int					to_die;
	int					check;
	int					nb_check;
}						t_cycle;

typedef struct			s_argvparse
{
	char				*name;
	int					id;
	struct s_argvparse	*next;
}						t_argvparse;

t_game					*get_players(int argc, char **argv);
t_pc					*get_pc(t_player *player);
int						prepare_arena(t_player *player, t_pc *pc, char *arena);
int						check_if_id_use(int id, t_argvparse *argv);
int						usage(void);
int						get_pcs_struct(t_pc **pcs, t_player *player, int index);
t_game					*exit_error_get_player(int id, t_game *game,
															t_argvparse *argv);
t_player				*make_player_list(t_argvparse *argv, t_game *game,
																int interval);

/*
** parsing
*/
int						clear_dump(int *dump, t_argvparse **argv);
int						clear_verbose(int *verb, t_argvparse **argv);
int						clear_n_option(t_argvparse **argv);
int						check_is_correct_champ(t_argvparse *argv, t_game *game);
int						clear_verbose_option(int *dump, t_argvparse **argv);

/*
** struct game
*/
t_game					*new_game();
void					release_game(t_game *game);

/*
** struct player
*/
t_player				*new_player(void);
void					release_player(t_player **player);
void					add_in_player_list(t_player **player,
											t_player *to_add);

/*
** struct pcs
*/
void					release_pcs(t_pc **pcs);
t_pc					*new_pc(int live);
void					push_in_front_pc(t_pc **pcs, t_pc *add);

/*
** struct argvparse
*/
t_argvparse				*new_argvparse(void);
void					release_argvparse(t_argvparse **argvparse);
void					free_item_argvparse(t_argvparse *argvparse);
void					add_in_argvparse_list(t_argvparse **argvparse,
												t_argvparse *to_add);

/*
** debug
*/
void					print_argv(t_argvparse *argv);
void					print_register(int *reg);
void					print_pcs_list(t_pc *pcs);
void					print_players_list(t_player *player);
void					print_game(t_game *game);

/*
** run game
*/
int						run(t_game *game);
int						run_pc(t_game *game);
void					*get_cmd(int opcode);
int						get_wait(int opcode);
void					check_cycle(t_cycle *cycle, t_game *game);

/*
** print
*/
void					print_winner(t_game *game);
void					print_cycle_current(t_game *game, int current);
void					print_cycle_to_die(t_game *game, int to_die);
void					print_pc_live(t_game *game, int live);
void					print_pc_kill(t_game *game);
void					print_aff(t_game *game, int c);
void					print_arena(const char *arena, int nb_octet);

#endif
