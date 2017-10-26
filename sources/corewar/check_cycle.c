/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:48:52 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/26 13:03:04 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*t_pc	*check_pc2(t_cycle *cycle, t_pc *pc, t_game *game)
{
	if (!pc)
		return (0);
	tmp = check_pc2(cycle, pc->next, game);
	if (cycle->current >= pc->last_live + cycle->to_die)
	{
		free(pc);
		print_pc_kill(game);
		(game->nb_pc)--;
		return (tmp);
	}
	else
	{
		pc->next = tmp;
		return (pc);
	}
}*/

void	destroy_pc(t_pc *pc, t_game *game)
{
	free(pc);
	print_pc_kill(game);
	(game->nb_pc)--;
}

void	check_pc(t_cycle *cycle, t_game *game)
{
	t_pc	*ptr;
	t_pc	*tmp;

	if (game->pcs != 0)
	{
		ptr = game->pcs;
		tmp = game->pcs->next;
		while (tmp != 0)
		{
			if (cycle->current >= tmp->last_live + cycle->to_die)
			{
				tmp = tmp->next;
				destroy_pc(ptr->next, game);
				ptr->next = tmp;
			}
			else
			{
				tmp = tmp->next;
				ptr = ptr->next;
			}
		}
		if (cycle->current >= game->pcs->last_live + cycle->to_die)
		{
			tmp = game->pcs;
			game->pcs = game->pcs->next;
			destroy_pc(tmp, game);
		}
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
		flag = 0;
		tmp = game->players;
		while (tmp != 0)
		{
			flag = tmp->nb_live < NBR_LIVE ? flag : 1;
			tmp->nb_live = 0;
			tmp = tmp->next;
		}
		if (flag)
			reset_cycle(cycle, game);
		else
		{
			(cycle->nb_check)++;
			if (cycle->nb_check == MAX_CHECKS)
				reset_cycle(cycle, game);
			else
				cycle->check += cycle->to_die;
		}
		check_pc(cycle, game);
	}
}
