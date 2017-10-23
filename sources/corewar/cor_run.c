/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:29:35 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 12:02:58 by pzarmehr         ###   ########.fr       */
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

void	end_game(t_game *game)
{
	if (!(game->pcs))
		print_winner(game);
	else
		;
}

int		run(t_game *game)
{
	t_cycle	c;
	int		ret;

	init_cycle(&c);
	//init_pc(game);
	while ((game->pcs != 0) &&
		(c.current < game->dump || game->dump == -1))
	{
		print_cycle_current(game, c.current);
		if ((ret = run_pc(game)) != 0)
			return (ret);
		c.current++;
		check_cycle(&c, game);
	}
	end_game(game);
	return (0);
}
