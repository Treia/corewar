/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:14:54 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/25 18:05:45 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_base(t_game *game, t_pc *pc, t_cycle *cycle)
{
	(void)game;
	(void)cycle;
	pc->addr = (pc->addr + 1) % MEM_SIZE;
	return (0);
}

void	*get_cmd2(int opcode)
{
	if (opcode == 10)
		return (&cmd_base);
	if (opcode == 11)
		return (&cmd_base);
	if (opcode == 12)
		return (&cmd_fork);
	if (opcode == 13)
		return (&cmd_base);
	if (opcode == 14)
		return (&cmd_base);
	if (opcode == 15)
		return (&cmd_lfork);
	if (opcode == 16)
		return (&cmd_base);
	return (&cmd_base);
}

void	*get_cmd(int opcode)
{
	//return (&cmd_base); //remove later
	if (opcode == 1)
		return (&cmd_live);
	if (opcode == 2)
		return (&cmd_base);
	if (opcode == 3)
		return (&cmd_base);
	if (opcode == 4)
		return (&cmd_add);
	if (opcode == 5)
		return (&cmd_sub);
	if (opcode == 6)
		return (&cmd_and);
	if (opcode == 7)
		return (&cmd_or);
	if (opcode == 8)
		return (&cmd_xor);
	if (opcode == 9)
		return (&cmd_zjmp);
	//return (&cmd_base); //remove later
	return (get_cmd2(opcode));
}
