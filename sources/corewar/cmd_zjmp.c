/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:00:43 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 17:48:37 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_zjmp(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tmp;

	(void)cycle;
	if (pc->carry)
		tmp = read_nb(game->arena, pc->addr + 1, 2) % IDX_MOD;
	else
		tmp = 3;
	return ((pc->addr + tmp) % MEM_SIZE);
}
