/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:29:35 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/21 16:43:03 by pzarmehr         ###   ########.fr       */
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
	t_cycle	c;
	int		ret;

	init_cycle(&c);
	while ((game->pcs != 0) &&
		(c.current < game->dump || game->dump == -1))
	{
		ret = run_pc(game, &c);
		if (ret != 0)
			return (ret);
		c.current++;
		check_cycle(&c, game);
	}
	end_game(game);
	return (0);
}
