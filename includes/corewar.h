/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 13:51:23 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/20 15:01:07 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

typedef	struct	s_player
{
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
	int					live;
	int					nb_live;
	struct s_player		next;
}				t_player;

typedef	struct	s_pc
{
	int					addr;
	int					reg[REG_NUMBER];
	int					carry;
	int					last_live;
	int					wait;
	struct s_pc			next;
}				t_pc;

#endif
