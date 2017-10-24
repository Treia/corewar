/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:00:43 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/24 18:09:59 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_zjmp(t_game *game, t_pc *pc, t_cycle *cycle)
{
	(void)cycle;
	if (pc->carry)
	{
		pc->addr += (short)read_nb(game->arena, pc->addr + 1, 2) % IDX_MOD;
	}
	else
		pc->addr += 3;
	pc->addr = pc->addr % MEM_SIZE;
	if (pc->addr < 0)
		pc->addr += MEM_SIZE;
	return (0);
}
