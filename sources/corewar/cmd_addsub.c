/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_addsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:40:56 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/25 17:22:58 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_add(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	next = get_next_addr(pc->addr, tab, 4, 3);
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 3)
		{
			pc->reg[tab[3]] = pc->reg[tab[1]] + pc->reg[tab[2]];
			pc->carry = (pc->reg[tab[3]] == 0 ? 1 : 0);
		}
	}
	pc->addr = next;
	return (0);
}

int		cmd_sub(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	next = get_next_addr(pc->addr, tab, 4, 3);
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 3)
		{
			pc->reg[tab[3]] = pc->reg[tab[1]] - pc->reg[tab[2]];
			pc->carry = (pc->reg[tab[3]] == 0 ? 1 : 0);
		}
	}
	pc->addr = next;
	return (0);
}
