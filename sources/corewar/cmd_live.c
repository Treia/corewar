/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:11:32 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/26 16:09:39 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_live(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int			live;
	t_player	*tmp;

	live = (int)read_nb(game->arena, pc->addr + 1, 4);
	tmp = game->players;
	while (tmp != 0)
	{
		if (tmp->live == live)
			(tmp->nb_live)++;
		tmp = tmp->next;
	}
	pc->last_live = cycle->current;
	game->winner = live;
	print_pc_live(game, live);
	pc->addr = ((pc->addr + 5) % MEM_SIZE);
	return (0);
}
