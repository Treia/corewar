/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:48:52 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 13:16:11 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_pc	*check_pc(t_cycle *cycle, t_pc *pc, t_game *game)
{
	t_pc	*tmp;

	if (pc == 0)
		return (0);
	tmp = check_pc(cycle, pc->next, game);
	if (cycle->current >= pc->last_live + cycle->to_die)
	{
		free(pc);
		print_pc_kill(game);
		return (tmp);
	}
	else
	{
		pc->next = tmp;
		return (pc);
	}
}

void	reset_cycle(t_cycle *cycle, t_game *game)
{
	t_player	*tmp;

	cycle->to_die -= CYCLE_DELTA;
	print_cycle_to_die(game, cycle->to_die);
	cycle->check += cycle->to_die;
	cycle->nb_check = 0;
	tmp = game->players;
	while (tmp != 0)
	{
		tmp->nb_live = 0;
		tmp = tmp->next;
	}
}

void	check_cycle(t_cycle *cycle, t_game *game)
{
	int			flag;
	t_player	*tmp;

	if (cycle->current == cycle->check)
	{
		game->pcs = check_pc(cycle, game->pcs, game);
		flag = 0;
		tmp = game->players;
		while (tmp != 0)
		{
			flag = tmp->nb_live < NBR_LIVE ? flag : 1;
			tmp = tmp->next;
		}
		if (flag)
			reset_cycle(cycle, game);
		else
		{
			cycle->nb_check++;
			if (cycle->nb_check == MAX_CHECKS)
				reset_cycle(cycle, game);
		}
	}
}
