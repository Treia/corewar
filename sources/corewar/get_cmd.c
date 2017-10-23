/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:14:54 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 18:39:43 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_base(t_game *game, t_pc *pc, t_cycle *cycle)
{
	(void)game;
	(void)cycle;
	return ((pc->addr + 1) % MEM_SIZE);
}

int		read_nb(char *arena, int addr, int size)
{
	int		tmp;

	tmp = 0;
	while (size > 0)
	{
		tmp *= 256;
		tmp += (int)(arena[addr % MEM_SIZE]);
		addr++;
		size--;
	}
	return (tmp);
}

void	*get_cmd(int opcode)
{
	if (opcode == 9)
		return (&cmd_zjmp);
	if (opcode == 12)
		return (&cmd_fork);
	return (&cmd_base);
}
