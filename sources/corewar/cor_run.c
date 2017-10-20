/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:29:35 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/20 20:10:31 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_cycle(t_cycle *cycle)
{
	cycle->current = 0;
	cycle->to_die = CYCLE_TO_DIE;
	cycle->check = CYCLE_TO_DIE;
	cycle->nb_check = 0;
}

void	reset_cycle(t_cycle *cycle, t_game *game)
{
	t_player	*tmp;

	cycle->to_die -= CYCLE_DELTA;
	cycle->check += cycle->to_die;
	cycle->nb_check = 0
	tmp = game->players;
	while (!tmp)
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
		flag = 0;
		tmp = game->players;
		while (!tmp)
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

void	end_game(t_game *game)
{
	if (!(game->pcs))
	{
		;//xxx win
	}
	else
		;//	dump memory	
}

int		run(t_game *game)
{
	t_cycle	cycle;

	init_cycle(&cycle);
	while ((game->pcs != 0) && (c.current < game->dump || game->dump == -1))
	{
		//pour chaque pc
		// si (cycle > pc->last_live + cycle_to_die)
		//		kill pc
		// sinon si (wait == 0)
		//		do cmd
		//		addr = next addr
		//		wait = next cmd;
		// sinon
		//		wait--;
		cycle.current++;
		check_cycle(&c);
	}
	end_game(game);
}