/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:40:44 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 18:24:43 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_fork(t_game *game, t_pc *pc, t_cycle *cycle)
{
	t_pc	*fork;

	(void)cycle;
	fork = (t_pc *)malloc(sizeof(t_pc));
	fork = ft_memcpy(fork, pc, sizeof(t_pc));
	fork->next = pc->next;
	pc->next = fork;
	pc->addr += read_nb(game->arena, pc->addr + 1, 2) % IDX_MOD;
	pc->addr = pc->addr % MEM_SIZE;
	fork->addr = ((fork->addr + 3) % MEM_SIZE);
	fork->cmd = get_cmd((game->arena)[fork->addr]);
	fork->wait = get_wait((game->arena)[fork->addr]);
	return (pc->addr);
}