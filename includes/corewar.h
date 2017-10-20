/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 13:51:23 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/20 18:42:37 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include <stdlib.h>

typedef	struct			s_player
{
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
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
	struct s_pc			*next;
}						t_pc;

typedef	struct			s_game
{
	t_player			*players;
	t_pc				*pcs;
	char				arena[MEM_SIZE];
	int					dump;
	int					verb;
}						t_game;

typedef	struct			s_cycle
{
	int					current;
	int					to_die;
	int					delta;
	int					check;
	int					nb_check;
}						t_cycle;

typedef struct			s_argvparse
{
	char				*name;
	int					id;
	struct s_argvparse	*next;
}						t_argvparse;

t_player				*get_players(int argc, char **argv, int *dump);
t_pc					*get_pc(t_player *player);
int						prepare_arena(t_player *player, t_pc *pc, char *arena);
int						run(t_player *players, t_pc *pc, char *arena, int dump);

/*
** structure player
*/
t_player				*new_player(void);
void					release_player(t_player **player);

#endif
